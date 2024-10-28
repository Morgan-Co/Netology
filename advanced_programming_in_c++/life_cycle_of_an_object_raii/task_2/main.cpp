#include <iostream>
#include <stdexcept>

struct SmartArray {
public:
	SmartArray(int size): size(size) {
		arr = new int[size];
		actual_size = 0;
	}

	SmartArray(const SmartArray& other) : size(other.size), actual_size(other.actual_size) {
		arr = new int[other.size];
		std::copy(other.arr, other.arr + other.size, arr);
	}

	SmartArray& operator=(const SmartArray& other) {
		if (this != &other)
		{
			delete[] arr;

			size = other.size;
			actual_size = other.actual_size;
			arr = new int[size];
			std::copy(other.arr, other.arr + other.size, arr);
		}
		return *this;
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

		SmartArray new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

		std::cout << "Element arr[0]: " << arr.get_element(0) << std::endl;
		std::cout << "Element arr[1]: " << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}