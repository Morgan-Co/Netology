#include <chrono> 
#include <exception>
#include <iomanip> 
#include <iostream>
#include <mutex>
#include <random>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>


const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

std::mutex output_mutex;

void progress_bar(int thread_number, int length, std::vector<std::string> &bars, std::vector<std::thread::id> &thread_ids) {
  auto start_time = std::chrono::steady_clock::now();

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 1500);
  std::uniform_real_distribution<> error_chance(0.0, 1.0); 

  for (int i = 0; i < length; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));

    try {
      if(error_chance(gen) < 0.1) {
        throw std::runtime_error("Simulated error");
      }

      {
        std::lock_guard<std::mutex> lock(output_mutex);
        bars[thread_number] = GREEN + std::string(i + 1, '#') + RESET + std::string(length - i - 1, ' ');

        std::cout << "\033[2J\033[H";
        std::cout << "#   id                Progress Bar            Time\n";
        for (size_t j = 0; j < bars.size(); j++) {
          std::cout << j << "   " << thread_ids[j] << "   [" << bars[j] << "]   \n";
        }
      }
    } catch (const std::exception &e) {
      {
        std::lock_guard<std::mutex> lock(output_mutex);
        bars[thread_number] = RED + std::string(i + 1, '#') + RESET + std::string(length - i - 1, ' ');

        std::cout << "\033[2J\033[H";
        std::cout << "#   id                Progress Bar            Time\n";
        for (size_t j = 0; j < bars.size(); j++) {
          std::cout << j << "   " << thread_ids[j] << "   [" << bars[j] << "]   \n";
        }
      }
    }
  }

  auto end_time = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed = end_time - start_time;

  {
    std::lock_guard<std::mutex> lock(output_mutex);
    bars[thread_number] += " " + std::to_string(elapsed.count()) + "s";
    std::cout << "\033[2J\033[H";
    std::cout << "#   id                Progress Bar            Time\n";
    for (size_t j = 0; j < bars.size(); j++) {
      std::cout << j << "   " << thread_ids[j] << "   [" << bars[j] << "]   \n";
    }
  }
}

int main() {
  const int thread_count = 5;
  const int bar_length = 20;

  std::vector<std::string> bars(thread_count, std::string(bar_length, ' '));
  std::vector<std::thread> threads;
  std::vector<std::thread::id> thread_ids(thread_count);

  for (int i = 0; i < thread_count; i++) {
    threads.emplace_back([&, i]() {
      thread_ids[i] = std::this_thread::get_id();
      progress_bar(i, bar_length, bars, thread_ids);
    });  
  }

  for (auto &thread : threads) {
    thread.join();
  }
}
