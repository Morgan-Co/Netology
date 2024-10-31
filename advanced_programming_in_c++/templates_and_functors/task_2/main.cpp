#include <iostream>
#include <vector>

template <typename T>
class Table {
public:
	Table(int rows, int cols)
		: data(rows, std::vector<T>(cols)) {}

	std::vector<T>& operator[](int row) {
		return data[row];
	}

	const std::vector<T>& operator[](int row) const {
		return data[row];
	}

	std::pair<int, int> Size() const {
		if (data.empty()) return { 0,0 };
		return { data.size(), data[0].size() };
	}

private:
	std::vector<std::vector<T>> data;
};

int main() {
	Table<int> table(2, 3);
	table[0][0] = 4;
	std::cout << table[0][0] << std::endl;

	auto size = table.Size();
	std::cout << "Rows: " << size.first << ", Columns: " << size.second << std::endl;

	return 0;
}