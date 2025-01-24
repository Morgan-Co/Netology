#include <iomanip>
#include <iostream>
#include <chrono>
#include <random>
#include <utility>
#include <vector>
#include <thread>
#include <functional>



std::vector<int> generate_random_vector(size_t size, int min = 1, int max = 100) {
  std::vector<int> vec(size);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(min, max);

  for (size_t i = 0; i < size; i++) {
      vec[i] = dist(gen);
  }

  return vec;
}

void sum_vectors
(const std::vector<int> &first_vec, const std::vector<int> &second_vec, std::vector<int> &result_vec, size_t start, size_t end ) {

  for (int i = start; i < end; i++) {
      result_vec[i] = first_vec[i] + second_vec[i];
  }
}

int main() {
    std::vector<size_t> test_sizes { 1000, 10000, 100000, 1000000 };
    std::vector<int> nums_threads { 1, 2, 4, 8, 16 };
    std::vector<std::vector<double>> results(nums_threads.size(), std::vector<double>(test_sizes.size()));



    for (int test_index = 0; test_index < test_sizes.size(); test_index++) {
      size_t size = test_sizes[test_index];
      std::pair<int, std::vector<double>> duration_thread; 
      std::vector<int> first_vec = generate_random_vector(size);
      std::vector<int> second_vec = generate_random_vector(size);
      std::vector<int> result_vec(size);


      for (int thread_index = 0; thread_index < nums_threads.size(); thread_index++) {
          size_t num_thread = nums_threads[thread_index];
          std::vector<std::thread> threads;
          size_t chunk_size = size / num_thread;
          auto start_time = std::chrono::high_resolution_clock::now();
          for (int i = 0; i < num_thread; i++) {
              size_t start = i * chunk_size;
              size_t end = (i == num_thread - 1) ? size : start + chunk_size;
              threads.emplace_back(sum_vectors, std::cref(first_vec), std::cref(second_vec), std::ref(result_vec), start, end);
          }
          for (auto &t : threads) {
            t.join();
          }
          auto end_time = std::chrono::high_resolution_clock::now();
          auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
          results[thread_index][test_index] = duration.count() / 1e9;
      }
    }


    std::cout << "Number of hardware cores: " << std::thread::hardware_concurrency() << std::endl;
    std::cout << std::setw(10) << " " << std::setw(10) << "1000" << std::setw(10) << "10000"
            << std::setw(10) << "100000" << std::setw(10) << "1000000" << "\n";

    for (size_t thread_index = 0; thread_index < nums_threads.size(); thread_index++) {
      std::cout << "threads: " << nums_threads[thread_index];
      for (size_t test_index = 0; test_index < test_sizes.size(); test_index++) {
        std::cout << std::setw(10) << std::fixed << std::setprecision(6) << results[thread_index][test_index] << "s";
      }
      std::cout << "\n";
    }
    return 0;
}
