#pragma once
#include <iostream>

using namespace std;

/*
* Print an array A in the format { a1, a2, ... }
*
* Params:
* - A, an array of printable elements (e.g. numbers, strings);
* - n, the length of the array
* - newline, a boolean indicating whether a newline be appended to the output. Defaults to false.
*/
template<typename T>
void print_array(T* A, size_t n, bool newline=false) {
  cout << "{ ";
  for (int i = 0; i < n; i++) {
    cout << A[i];
    if (i != n-1) cout << ", ";
  }
  cout << " }";
  if (newline) cout << endl;
}