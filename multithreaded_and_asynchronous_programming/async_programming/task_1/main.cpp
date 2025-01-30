#include <future>
#include <iostream>

int findMinIndex(int arr[], int start, int end) {
  int minIndex = start;
  for (int i = start + 1; i <= end; i++) {
    if(arr[i] < arr[minIndex]) {
      minIndex = i;
    }
  }
  return minIndex;
}



void selectionSortAsync(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
      std::future<int> minIndexFuture = std::async(std::launch::async, findMinIndex, arr, i, n - 1);

      int minIndex = minIndexFuture.get();
      
      std::swap(arr[i], arr[minIndex]);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] { 5,3,8,1,2 };
  int n = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Initial array: ";
  printArray(arr, n)  ;

  selectionSortAsync(arr, n);

  std::cout << "Sorted array: ";
  printArray(arr, n);
}
