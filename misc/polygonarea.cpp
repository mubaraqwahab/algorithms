#include <iostream>

using namespace std;

struct vector {
  double x,y;
};

/**
 * Compute the area of an arbitrary polygon using Green's theorem
 *
 * Params:
 * - an array V of vertices, where each vertex is a position vector (x,y) in the Cartesian plane. The vertices should be ordered as they "appear" in the polygon.
 * - n, the number of vertices of the polygon.
 *
 * Output:
 * - The area of the polygon
*/
double green(vector V[], int n);

/**
 * Compute the area of an arbitrary polygon by exploiting the cross product formula
 *
 * Params:
 * - an array V of vertices, where each vertex is a position vector (x,y) in the Cartesian plane. The vertices should be ordered as they "appear" in the polygon.
 * - n, the number of vertices of the polygon.
 *
 * Output:
 * - The area of the polygon
*/
double crossproduct(vector V[], int n);

// Test drive
int main() {
  #define N 5
  vector v1 = {0,3};
  vector v2 = {3,0};
  vector v3 = {5,1};
  vector v4 = {4,4};
  vector v5 = {1,5};
  vector V[N] = { v1, v2, v3, v4, v5 };

  cout << "Polygon Area" << endl;
  cout << "Green's theorem: " << green(V, N) << endl;
  cout << "Cross product: " << crossproduct(V, N) << endl;

  return 0;
}

double green(vector V[], int n) {
  double area = 0;
  // TODO
  return area;
}

double crossproduct(vector V[], int n) {
  double area = 0;
  // TODO
  return area;
}
