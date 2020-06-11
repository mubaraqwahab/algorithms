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
  for (int i = 0, j; i < n; i++) {
    j = (i+1) % n;
    area += (V[j].x + V[i].x) * (V[j].y - V[i].y);
  }
  area /= 2;
  return area;
}

double crossproduct(vector V[], int n) {
  double area = 0, L;
  vector v0, u1, u2;
  v0 = V[0];
  // Careful! This wouldn't work before C++11
  u1 = { V[1].x - v0.x, V[1].y - v0.y };
  for (int i = 1; i < n-1; i++) {
    u2 = { V[i+1].x - v0.x, V[i+1].y - v0.y };
    L = abs(u1.x*u2.y - u1.y*u2.x);
    area += L;
    u1 = u2;
  }
  area /= 2;
  return area;
}
