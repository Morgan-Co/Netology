#include <iostream>
#include <mutex>
#include <utility>

class Data {
public:
  explicit Data(int value)
    : value(value) {}

  int getValue() const { return value; }

private:
  int value;
  mutable std::mutex mtx;

  friend void swap_lock(Data &a, Data &b);
  friend void swap_scoped_lock(Data &a, Data &b);
  friend void swap_unique_lock(Data &a, Data &b);
};

void swap_lock(Data &a, Data &b) {
  if (&a == &b) return;

  std::lock(a.mtx, b.mtx);

  std::lock_guard<std::mutex> lock_a(a.mtx, std::adopt_lock);
  std::lock_guard<std::mutex> lock_b(b.mtx, std::adopt_lock);

  std::swap(a.value, b.value);
}

void swap_scoped_lock(Data &a, Data &b) {
  if (&a == &b) return;

  std::scoped_lock lock(a.mtx, b.mtx);

  std::swap(a.value, b.value);
}

void swap_unique_lock(Data &a, Data &b) {
  if (&a == &b) return;

  std::unique_lock<std::mutex> lock_a(a.mtx, std::defer_lock);
  std::unique_lock<std::mutex> lock_b(b.mtx, std::defer_lock);

  std::lock(lock_a, lock_b);

  std::swap(a.value, b.value);
}

void printData(const Data &a, const Data &b) {
  std::cout << "Data A: " << a.getValue() << ", Data B: " << b.getValue() << std::endl;
}

int main() {
  Data a(10);
  Data b(20);

  std::cout << "Initial values: " << std::endl;
  printData(a, b);

  std::cout << "\nUsing swap_lock: " << std::endl;
  swap_lock(a, b);
  printData(a, b);

  std::cout << "\nUsing swap_scoped_lock: " << std::endl;
  swap_scoped_lock(a, b);
  printData(a, b);

  std::cout << "\nUsing swap_unique_lock: " << std::endl;
  swap_unique_lock(a, b);
  printData(a, b);

  return 0;
}
