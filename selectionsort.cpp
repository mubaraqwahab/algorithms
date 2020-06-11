#include <iostream>
#include "utils.h"

using namespace std;

template<typename T>
void selectionsort(T* array, size_t n) {
  T min;
  for (int i = 0; i < n-1; i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
      if (array[j] < array[min]) min = j;
    }
    swap(array[i], array[min]);
  }
}

//
int main() {
  #define N 7
  int array[] = { 89,45,68,90,29,34,17 };
  cout << "Before: ";
  print_array(array, N, true);

  selectionsort(array, N);

  cout << "After: ";
  print_array(array, N, true);

  return 0;
}
/**/