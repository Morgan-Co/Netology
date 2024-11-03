#include <iostream>
#include <string>
#include <map>

int main() {
	std::string text;
	std::cout << "Enter some text: ";
	std::getline(std::cin, text);

	std::map<char, int> frequency;
	for (char ch : text)
	{
		frequency[ch]++;
	}

	std::multimap<int, char, std::greater<int>> sorted_frequency;
	for (const auto& pair : frequency)
	{
		sorted_frequency.insert({ pair.second, pair.first });
	}

	for (const auto& pair : sorted_frequency) {
		std::cout << pair.second << ": " << pair.first << '\n';
	}

	return 0;
}