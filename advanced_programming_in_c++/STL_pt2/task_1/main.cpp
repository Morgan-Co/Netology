#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void deleteDuplicates(std::vector<T>& vec) {
	std::sort(vec.begin(), vec.end());
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
}

int main() {
	std::vector<int> nums{ 1,2,3,4,5,5,6,7,8,8,7,6,5,4,3,3,4,5,6 };
	deleteDuplicates(nums);


	for (const auto& el : nums)
	{
		std::cout << el << std::endl;
	}
}