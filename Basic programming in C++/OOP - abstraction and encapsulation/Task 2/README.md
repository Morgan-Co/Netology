```
#include <string>
#include <fstream>
#include <iostream>


class Address {
	std::string city, street;
	int house, apartment;
public:
	Address() {}
	Address(std::string& city, std::string& street, int house, int apartment) :
		city(city), street(street), house(house), apartment(apartment) {}

	std::string getOutputAddress() {
		return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
	}

	std::string getCity() {
		return city;
	}
};


void sort(Address* addresses, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++) {
			if (addresses[i].getCity() > addresses[j].getCity())
			{
				std::swap(addresses[i], addresses[j]);
			}
		}
	}
}


int main() {
	std::ifstream inputFile("in.txt");
	std::ofstream outputFile("out.txt");

	int N;
	inputFile >> N;
	inputFile.ignore();
	Address* addresses = new Address[N];

	for (int i = 0; i < N; i++) {
		std::string city, street;
		int house, apartment;

		std::getline(inputFile, city);
		std::getline(inputFile, street);
		inputFile >> house >> apartment;
		inputFile.ignore();

		addresses[i] = Address(city, street, house, apartment);
	}
	sort(addresses, N);

	outputFile << N << std::endl;

	for (int i = 0; i < N; i++)
	{
		outputFile << addresses[i].getOutputAddress() << std::endl;
	}

	delete[] addresses;

	inputFile.close();
	outputFile.close();

	return 0;
}
```