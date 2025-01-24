#include <chrono>
#include <iostream>
#include <thread>


void increase(int &clients_count) {
  for (int i = 0; i < 20; i++) {
    clients_count++;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  
   std::cout << "Clients count: " << clients_count << "\tTHREAD ID: " << std::this_thread::get_id() << "\tINCREASE" << std::endl;
  }
}

void clients_operator(int &clients_count) {
  while(clients_count != 0) {
   clients_count--;
   std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  
   std::cout << "Clients count: " << clients_count << "\tTHREAD ID: " << std::this_thread::get_id() << "\tCLIENTS OPERATOR" << std::endl;
  }
}


int main() {

  int clients_count = 5;

  std::thread increase_thread(increase, std::ref(clients_count));
  std::thread operator_thread(clients_operator, std::ref(clients_count));


  operator_thread.join();
}
