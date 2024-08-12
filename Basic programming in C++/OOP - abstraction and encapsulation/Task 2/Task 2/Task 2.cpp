#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    // Конструктор класса
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    // Метод для получения строки формата вывода адреса
    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    // Метод для получения названия города
    std::string getCity() const {
        return city;
    }

    // Оператор сравнения для сортировки
    bool operator<(const Address& other) const {
        return city < other.city;
    }
};

int main() {
    std::ifstream inFile("in.txt");
    std::ofstream outFile("out.txt");

    int n;
    inFile >> n;  // Читаем количество адресов
    inFile.ignore();  // Игнорируем символ новой строки после числа

    std::vector<Address> addresses;

    for (int i = 0; i < n; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        std::getline(inFile, city);
        std::getline(inFile, street);
        inFile >> houseNumber >> apartmentNumber;
        inFile.ignore();  // Игнорируем символ новой строки после номеров

        addresses.emplace_back(city, street, houseNumber, apartmentNumber);
    }

    // Сортируем адреса по названию города
    std::sort(addresses.begin(), addresses.end());

    // Записываем количество адресов в файл
    outFile << n << std::endl;

    // Записываем отсортированные адреса
    for (const auto& address : addresses) {
        outFile << address.getOutputAddress() << std::

