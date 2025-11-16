#include <iostream>

class Date {
	private:
		int day;
		int month;
		int year;

		static const int daysInMonth[12];

		bool isLeapYear(int year) const {
			return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
		}

		int daysInCurrentMonth(int month, int year) const {
			if (month == 2) {
				return isLeapYear(year) ? 29 : 28;
			}
			return daysInMonth[month - 1];
		}

		int toDays() const {
			int totalDays = 0;

			for (int y = 0; y < year; ++y) {
				totalDays += isLeapYear(y) ? 366 : 365;
			}

			for (int m = 0; m < month; ++m) {
				totalDays += daysInCurrentMonth(m, year);
			}

			totalDays += day;
			return totalDays;
		}

		void fromDays(int totalDays) {
			year = 0;

			while (true) {
				int yearDays = isLeapYear(year) ? 366 : 365;
				if (totalDays > yearDays) {
					totalDays -= yearDays;
					++year;
				}
				else {
					break;
				}
			}

			month = 1;
			while (true) {
				int monthDays = daysInCurrentMonth(month, year);

				if (totalDays > monthDays) {
					totalDays -= monthDays;
					++month;
				}
				else {
					break;
				}
			}
		
			day = (int)totalDays;
		}

	public:
		Date(int d = 1, int m = 1, int y = 0) : day(d), month(m), year(y) {}

		int operator-(const Date& other) const {
			return this->toDays() - other.toDays();
		}

		Date& operator+=(int days) {
			int total = toDays();
			total += days;
			fromDays(total);
			return *this;
		}

		void print() const {
			std::cout << day << "." << month << "." << year << std::endl;
		}
};

const int Date::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	Date date1(25, 11, 2025);
	Date date2(25, 11, 1);

	std::cout << date1 - date2 << std::endl;

	date1 += 20;
	date1.print();

}
