#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

class FileManager {
private:
	std::string basePath;
	std::filesystem::path fullPath(const std::filesystem::path& relativePath) const {
		return basePath / relativePath;
	}

public:
	FileManager(const std::string& base) : basePath(base) {
		if (!std::filesystem::exists(basePath)) {
			std::filesystem::create_directories(basePath);
		}
	}

	bool createFile(const std::string& relativePath) {
		auto filePath = fullPath(relativePath);
		std::ofstream ofs(filePath);

		if (!ofs) {
			std::cerr << "Ошибка создания файла";
			return false;
		}

		ofs.close();
		return true;
	}

	bool createDirectory(const std::string& relativePath) {
		auto dirPath = fullPath(relativePath);
		if (!std::filesystem::exists(dirPath)) {
			return std::filesystem::create_directories(dirPath);
		}
		return false;
	}

	bool fileExists(const std::string& relativePath) {
		auto filePath = fullPath(relativePath);
		return std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath);
	}

	bool directoryExists(const std::string& relativePath) {
		auto dirPath = fullPath(relativePath);
		return std::filesystem::exists(dirPath) && std::filesystem::is_directory(dirPath);
	}

	std::vector<std::string> listFiles(const std::string& relativePath) {
		std::vector<std::string> files;
		auto dirPath = fullPath(relativePath);

		if (directoryExists(relativePath)) {
			for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {

				files.push_back(entry.path().filename().string());

			}
		}

		return files;
	}

	bool removeFile(const std::string& relativePath) {
		auto filePath = fullPath(relativePath);

		if (fileExists(relativePath)) {
			return std::filesystem::remove(filePath);
		}

		return false;
	}

	bool removeDirectory(const std::string& relativePath) {
		auto dirPath = fullPath(relativePath);

		if (directoryExists(relativePath)) {
			return std::filesystem::remove(dirPath);
		}

		return false;
	}
};

int main()
{
	FileManager fm("test_base");

	std::cout << "Создадим папку 'test_dir': " << fm.createDirectory("test_dir") << std::endl;

	std::cout << "Создадим файл: 'test_dir/file1.txt': " << fm.createFile("test_dir/file1.txt") << std::endl;
	std::cout << "Создадим файл: 'test_dir/file2.txt': " << fm.createFile("test_dir/file2.txt") << std::endl;
	std::cout << "Создадим файл: 'test_dir/file3.txt': " << fm.createFile("test_dir/file3.txt") << std::endl;

	std::cout << "Файлы в 'test_dir': " << std::endl;
	for (auto f : fm.listFiles("test_dir")) {
		std::cout << " " << f << std::endl;
	}
}
