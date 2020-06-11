#include <iostream>
#include "utils.h"

using namespace std;

template<typename T>
void bubblesort(T* A, size_t n) {
  int swaps, k = 0;
  for (int i = 0; i < n-1; i++) {
    swaps = 0;
    for (int j = 0; j < n-1; j++) {
      k++;
      if (A[j] > A[j+1]) {
        swap(A[j], A[j+1]);
        swaps++;
      }
    }
    if (swaps == 0) break;
  }
  cout << k << endl;
}

//
int main() {
  #define N 7
  int A[] = { 89,45,68,90,29,34,17 };
  print_array(A, N, true);

  bubblesort(A, N);

  print_array(A, N, true);

  return 0;
}
/**/