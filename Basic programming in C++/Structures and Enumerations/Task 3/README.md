```
#include <iostream>
#include <string>

struct Address {
	std::string city, street;
	int houseNumber, apartmentNumber, index;

	Address(std::string city, std::string street, int houseNumber, int apartmentNumber, int index)
		: city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber), index(index) {}

	// It could be a method like this ---------------------

	/*void print_address() {
		std::cout << "City: " << city << std::endl;
		std::cout << "Street: " << street << std::endl;
		std::cout << "House number: " << houseNumber << std::endl;
		std::cout << "Apartment number: " << apartmentNumber << std::endl;
		std::cout << "Index: " << index << std::endl << std::endl;
	}*/
};

void print_adress(Address &address) {
	std::cout << "City: " << address.city << std::endl;
	std::cout << "Street: " << address.street << std::endl;
	std::cout << "House number: " << address.houseNumber << std::endl;
	std::cout << "Apartment number: " << address.apartmentNumber << std::endl;
	std::cout << "Index: " << address.index << std::endl << std::endl;
}

int main()
{
	Address address_1("Moscow", "Arbat", 12, 8, 111222);
	print_adress(address_1);
	Address address_2("New York", "Some street", 60, 40, 666999);
	print_adress(address_2);

}
```