#include  <iostream>
#include "utils.h"

using namespace std;

template<typename T>
int sequentialsearch(T* array, size_t n, T key) {
  int i = 0;
  while (i < n && array[i] != key) {
    i = i + 1;
  }
  if (i < n) return i;
  else return -1;
}

//
int main() {
  #define N 7
  int array[] = { 89,45,68,90,29,34,17 };
  int key = 90;
  int position = sequentialsearch(array, N, 90);

  if (position != -1) {
    cout << key << " is in ";
    print_array(array, N);
    cout << " at position " << position << endl;
  } else {
    cout << key << " is not in ";
    print_array(array, N, true);
  }

  return 0;
}
/**/