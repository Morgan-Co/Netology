#include <iostream>
#include <vector>
#include <algorithm>


template <class T>
T square(T num) {
	return num * num;
}

template <class T>
std::vector<T> square(const std::vector<T>& vec) {
	std::vector<T> result(vec.size());
	std::transform(vec.begin(), vec.end(), result.begin(), [](T val){
		return val * val;
	});
	return result;
}


int main() {
	int num = 8;
	std::cout << "Square of " << num << " is " << square(num) << std::endl;

	std::vector<int> nums{ 1,2,3,4,5,6,7,8 };
	std::vector<int> squared_nums = square(nums);
	for (const auto& num : squared_nums) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}