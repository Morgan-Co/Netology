#include <iostream>

enum Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main() {
	int monthNumber;
	do
	{
		std::cout << "Enter the month number: ";
		std::cin >> monthNumber;
		Month month = static_cast<Month>(monthNumber);

		switch (monthNumber)
		{
		case January: {
			std::cout << "January" << std::endl;
			break;
		}
		case February: {
			std::cout << "February" << std::endl;
			break;
		}
		case March: {
			std::cout << "March" << std::endl;
			break;
		}
		case April: {
			std::cout << "April" << std::endl;
			break;
		}
		case May: {
			std::cout << "May" << std::endl;
			break;
		}
		case June: {
			std::cout << "June" << std::endl;
			break;
		}
		case 0: {
			break;
		}
		default:
			std::cout << "Invalid case!" << std::endl;
			break;
		}
	} while (monthNumber != 0);
	std::cout << "Goodbye!" << std::endl;
}