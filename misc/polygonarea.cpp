#include <iostream>
#include <vector>

using namespace std;

struct vertex
{
  double x, y;
};

/**
 * Compute the area of an arbitrary polygon using Green's theorem
 *
 * Params:
 * - an array V of n vertices of the polygon, where each vertex is a position vector (x,y) in the Cartesian plane. The vertices should be ordered as they "appear" in the polygon.
 *
 * Output:
 * - The area of the polygon
*/
double green(vector<vertex> V)
{
  double area = 0;
  // TODO
  return area;
}

/**
 * Compute the area of an arbitrary polygon by exploiting the cross product formula
 *
 * Params:
 * - an array V of n vertices of the polygon, where each vertex is a position vector (x,y) in the Cartesian plane. The vertices should be ordered as they "appear" in the polygon.
 *
 * Output:
 * - The area of the polygon
*/
double crossproduct(vector<vertex> V)
{
  double area = 0;
  // TODO
  return area;
}

// Test drive
int main()
{
  // #define N 5
  // vertex v1 = {0, 3};
  // vertex v2 = {3, 0};
  // vertex v3 = {3, 0};
  // vertex v4 = {4, 4};
  // vertex v5 = {1, 5};
  // vertex V[N] = {v1, v2, v3, v4, v5};

  vector<vertex> V{{{0, 3}, {3, 0}, {3, 0}, {4, 4}, {1, 5}}};

  cout << "Polygon Area" << endl;
  cout << "Green's theorem: " << green(V) << endl;
  cout << "Cross product: " << crossproduct(V) << endl;

  return 0;
}