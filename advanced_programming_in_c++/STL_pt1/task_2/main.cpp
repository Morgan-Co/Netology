#include <iostream>
#include <set>

int main() {
	int n;
	std::cout << "Enter count of elements: ";
	std::cin >> n;

	std::set<int, std::greater<int>> unique_numbers;

	for (int i = 0; i < n; i++) {
		int number;
		std::cout << "El " << i + 1 << ": ";
		std::cin >> number;
		unique_numbers.insert(number);
	}

	std::cout << "Your set:";
	for (int number : unique_numbers)
	{
		std::cout << number << "\n";
	}

	return 0;
}