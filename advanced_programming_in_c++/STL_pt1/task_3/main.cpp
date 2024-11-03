#include <iostream>
#include <stdexcept>


template <typename T>
class Vector {
private:
	void resize() {
		int new_capacity = (current_capacity == 0) ? 1 : current_capacity * 2;
		T* new_data = new T[new_capacity];

		if (new_capacity < current_size) throw std::runtime_error("Insufficient capacity for resize");


		for (int i = 0; i < current_size; i++)
		{
			new_data[i] = data[i];
		}

		delete[] data;
		data = new_data;
		current_capacity = new_capacity;
	}
public:
	Vector() : data(nullptr), current_size(0), current_capacity(0) {}

	~Vector() {
		delete[] data;
	}

	T& at(int index) {
		if (index < 0 || index >= current_size) throw std::out_of_range("Index out of range");
		return data[index];
	}

	void push_back(const T& value) {
		if (current_size == current_capacity) resize();
		data[current_size++] = value;
	}

	int size() const {
		return current_size;
	}

	int capacity() const {
		return current_capacity;
	}

private:
	T* data;
	int current_size;
	int current_capacity;
};

int main() {
	Vector<int> vec;

	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(6);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "vec[" << i << "] = " << vec.at(i) << std::endl;
	}

	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
}