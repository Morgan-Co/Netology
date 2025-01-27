#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>


void increase(std::atomic<int> &clients_count) {
  for (int i = 0; i < 20; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    clients_count.fetch_add(1, std::memory_order_acq_rel); 
    std::cout << "Clients count: " << clients_count << "\tTHREAD ID: " << std::this_thread::get_id() << "\tINCREASE" << std::endl;
  }
}

void clients_operator(std::atomic<int> &clients_count) {
  while(clients_count != 0) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    clients_count.fetch_sub(1, std::memory_order_acq_rel);
    std::cout << "Clients count: " << clients_count << "\tTHREAD ID: " << std::this_thread::get_id() << "\tCLIENTS OPERATOR" << std::endl;
  }
}


int main() {

  std::atomic<int> clients_count = 5;

  std::thread increase_thread(increase, std::ref(clients_count));
  std::thread operator_thread(clients_operator, std::ref(clients_count));

  increase_thread.join();
  operator_thread.join();
}
