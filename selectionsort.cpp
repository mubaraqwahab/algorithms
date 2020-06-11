#include <iostream>
#include "utils.h"

using namespace std;

template<typename T>
void selectionsort(T* A, size_t n) {
  T min;
  for (int i = 0; i < n-1; i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
      if (A[j] < A[min]) min = j;
    }
    swap(A[i], A[min]);
  }
}

//
int main() {
  #define N 7
  int A[] = { 89,45,68,90,29,34,17 };
  print_array(A, N, true);

  selectionsort(A, N);

  print_array(A, N, true);

  return 0;
}
/**/