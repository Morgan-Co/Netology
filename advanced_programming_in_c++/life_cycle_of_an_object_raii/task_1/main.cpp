#include <iostream>
#include <stdexcept>

struct SmartArray {
public:
	SmartArray(int size): size(size) {
		arr = new int[size];
		actual_size = 0;
	}

	void add_element(int value) {
		if (actual_size < size)
		{
			arr[actual_size] = value;
			actual_size++;
		}
		else {
			throw std::out_of_range("The array is full");
		}
	}
	int get_element(int index) {
		if (index >= size) {
			throw std::out_of_range("Invalid index");
		}
		return arr[index];
	}
	~SmartArray() {
		delete[] arr;
	}
private:
	int size;
	int actual_size;
	int* arr;
};

int main() {
	try
	{
		SmartArray arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//arr.add_element(64);
		std::cout << arr.get_element(4);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}