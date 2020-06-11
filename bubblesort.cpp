#include <iostream>
#include "utils.h"

using namespace std;

template<typename T>
void bubblesort(T* array, size_t n) {
  int swaps;
  for (int i = 0; i < n-1; i++) {
    swaps = 0;
    for (int j = 0; j < n-1; j++) {
      if (array[j] > array[j+1]) {
        swap(array[j], array[j+1]);
        swaps++;
      }
    }
    if (swaps == 0) break;
  }
}

//
int main() {
  #define N 7
  int array[] = { 89,45,68,90,29,34,17 };
  cout << "Before: ";
  print_array(array, N, true);

  bubblesort(array, N);

  cout << "After: ";
  print_array(array, N, true);

  return 0;
}
/**/