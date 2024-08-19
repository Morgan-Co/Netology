```
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class Address {
	std::string city, street;
	int house_number = 0, apartment_number = 0;

public:
	Address(std::string city, std::string street, int house_number, int apartment_number) :
		city(city), street(street), house_number(house_number), apartment_number(apartment_number) {}

	std::string getOutputAddress() {
		return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
	}
};

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	std::ifstream in_file("in.txt");
	std::ofstream out_file("out.txt");

	int n;
	in_file >> n;
	in_file.ignore();

	std::vector<Address> addresses;

	for (int i = 0; i < n; i++)
	{
		std::string city, street;
		int house_number, apartment_number;

		std::getline(in_file, city);
		std::getline(in_file, street);
		in_file >> house_number >> apartment_number;
		in_file.ignore();

		addresses.emplace_back(city, street, house_number, apartment_number);
	}

	out_file << n << std::endl;

	for (int i = n - 1; i >= 0; i--) {
		out_file << addresses[i].getOutputAddress() << std::endl;

	}

	in_file.close();
	out_file.close();

	return 0;
}

```