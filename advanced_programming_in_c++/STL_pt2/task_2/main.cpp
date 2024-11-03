#include <iostream>
#include <set>
#include <vector>
#include <list>

template <typename Container>
void print_container(const Container& container) {
	for (const auto& element : container)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::set<std::string> test_set{"one", "two", "three", "four"};
	std::vector<int> test_vector{ 1,2,3,4,5,6,7 };
	std::list<double> test_list{ 1.1,2.2, 2.3, 3.4 };

	std::cout << "Set: ";
	print_container(test_set);

	std::cout << "Vector: ";
	print_container(test_vector);

	std::cout << "List: ";
	print_container(test_list);
}