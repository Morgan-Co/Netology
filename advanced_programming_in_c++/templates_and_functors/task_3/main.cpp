#include <iostream>
#include <vector>
#include <algorithm>

class DivisibleByThreeCounter {
public:
	void operator()(int number) {
		if (number % 3 == 0)
		{
			sum += number;
			count++;
		}
	}

	int get_sum() {
		return sum;
	}

	int get_count() {
		return count;
	}
private:
	int sum = 0;
	int count = 0;
};


int main() {
	std::vector<int> numbers = { 4,1,3,6,25,54 };

	DivisibleByThreeCounter counter;

	std::for_each(numbers.begin(), numbers.end(), std::ref(counter));

	std::cout << "get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "get_count() = " << counter.get_count() << std::endl;
}