#include <algorithm>
#include <future>
#include <iterator>
#include <vector>
#include <iostream>

constexpr size_t MIN_BLOCK_SIZE = 1000;

template <typename Iterator, typename Func>
void parallel_for_each(Iterator begin, Iterator end, Func&& func) {
  auto length = std::distance(begin, end);
  if (length <= MIN_BLOCK_SIZE) {
    std::for_each(begin, end, func);
    return;
  }

  Iterator mid = begin;
  std::advance(mid, length / 2);
  
  auto future = std::async(std::launch::async, parallel_for_each<Iterator, Func>, begin, mid, std::forward<Func>(func));

  future.wait();
}

int main() {
  std::vector<int> data(10000, 1);

  parallel_for_each(data.begin(), data.end(), [](int &n) {
      n *= 2;
  });

  std::cout << "First 10 elements: ";

  for (int i = 0; i < 10; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}
