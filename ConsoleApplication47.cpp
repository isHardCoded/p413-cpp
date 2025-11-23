#include <iostream>

class Passport {
	protected:
		std::string citizenName;
		std::string passortNumber;
		std::string dateOfBirth;

	public:
		Passport(const std::string& citizenName, const std::string& passortNumber, const std::string& dateOfBirth)
			: citizenName(citizenName), passortNumber(passortNumber), dateOfBirth(dateOfBirth) {}

		virtual void Print() const {
			std::cout << "Citizen: " << citizenName << std::endl;
			std::cout << "Passport Number: " << passortNumber << std::endl;
			std::cout << "Date of birth: " << dateOfBirth << std::endl;
		}
};

class ForeignPassport : public Passport {
	private:
		std::string foreignPassportNumber;
		std::string visaInfo;

	public:
		ForeignPassport(const std::string& citizenName, const std::string& passortNumber, const std::string& dateOfBirth, const std::string& foreignPassportNumber, const std::string& visaInfo)
			: Passport(citizenName, passortNumber, dateOfBirth), foreignPassportNumber(foreignPassportNumber), visaInfo(visaInfo) {
		}

		void Print() const override {
			std::cout << "Citizen: " << citizenName << std::endl;
			std::cout << "Foreign Passport Number: " << foreignPassportNumber << std::endl;
			std::cout << "Visa Info: " << visaInfo << std::endl;

		}
};

int main()
{
	
}
