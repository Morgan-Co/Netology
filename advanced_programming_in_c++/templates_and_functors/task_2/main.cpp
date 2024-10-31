#include <iostream>
#include <stdexcept>

template <typename T>
class Table {
public:
    Table(size_t rows, size_t columns)
        : row_count(rows), column_count(columns) {
        data = new T * [row_count];
        for (size_t i = 0; i < row_count; i++) {
            data[i] = new T[column_count];
        }
    }

    ~Table() {
        for (size_t i = 0; i < row_count; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    T* operator[](size_t row) {
        if (row >= row_count) {
            throw std::out_of_range("The row index goes beyond the table");
        }
        return data[row];
    }

    const T* operator[](size_t row) const {
        if (row >= row_count) {
            throw std::out_of_range("The row index goes beyond the table");
        }
        return data[row];
    }

    std::pair<size_t, size_t> Size() const {
        return { row_count, column_count };
    }

private:
    T** data;
    size_t row_count;
    size_t column_count;
};

int main() {
    Table<int> table(2, 3);
    table[0][0] = 4;
    std::cout << table[0][0] << std::endl;

    auto size = table.Size();
    std::cout << "The size of the table: " << size.first << "  " << size.second << std::endl;

    return 0;
}
