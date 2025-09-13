#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

class FileManager {
private:
	std::string pathname;

public:
	FileManager(const std::string& pathname) {
		this->pathname = pathname;
	}

	bool createFile() {
		std::ofstream ofs(pathname);

		if (!ofs) {
			std::cerr << "Ошибка создания файла";
			return false;
		}

		ofs.close();
		return true;
	}

	bool fileExists() {
		return std::filesystem::exists(pathname);
	}

	bool writeFile(const std::string& content) {
		std::ofstream ofs(pathname);

		if (!ofs) {
			std::cerr << "Ошибка открытия файла для записи";
			return false;
		}

		ofs << content;
		ofs.close();
		return true;
	}

	bool removeFile() {
		if (std::filesystem::remove(pathname)) {
			return true;
		}
		else {
			std::cerr << "Ошибка удаления файла";
			return false;
		}

	}

	std::string readFile() {
		std::ifstream ifs(pathname);

		if (!ifs) {
			std::cerr << "Ошибка открытия файла для чтения";
			return "";
		}

		std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		return content;
	}


};

int main()
{
	FileManager fm("file.txt");

	if (!fm.fileExists()) {
		std::cout << "Файла не существует. Он будет создан: " << std::endl;
		fm.createFile();
	}
	fm.writeFile("Hello!");

	std::string content = fm.readFile();

	std::cout << "Содержимое файла: " << content << std::endl;

	if (fm.removeFile()) {
		std::cout << "Файл успешно удален" << std::endl;
	}
}
