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
    // ����������� ������
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    // ����� ��� ��������� ������ ������� ������ ������
    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    // ����� ��� ��������� �������� ������
    std::string getCity() const {
        return city;
    }

    // �������� ��������� ��� ����������
    bool operator<(const Address& other) const {
        return city < other.city;
    }
};

int main() {
    std::ifstream inFile("in.txt");
    std::ofstream outFile("out.txt");

    int n;
    inFile >> n;  // ������ ���������� �������
    inFile.ignore();  // ���������� ������ ����� ������ ����� �����

    std::vector<Address> addresses;

    for (int i = 0; i < n; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        std::getline(inFile, city);
        std::getline(inFile, street);
        inFile >> houseNumber >> apartmentNumber;
        inFile.ignore();  // ���������� ������ ����� ������ ����� �������

        addresses.emplace_back(city, street, houseNumber, apartmentNumber);
    }

    // ��������� ������ �� �������� ������
    std::sort(addresses.begin(), addresses.end());

    // ���������� ���������� ������� � ����
    outFile << n << std::endl;

    // ���������� ��������������� ������
    for (const auto& address : addresses) {
        outFile << address.getOutputAddress() << std::

