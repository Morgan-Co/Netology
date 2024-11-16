#include <iostream>
#include <vector>
#include <string>

template <class T>
void move_vectors(std::vector<T>& first_vec, std::vector<T>& second_vec) {
	second_vec = std::move(first_vec);
}

int main() {
	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;

	move_vectors(one, two);

	for (auto el : two)
	{
		std::cout << el << std::endl;
	}
}