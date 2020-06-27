#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
  double x, y;

  // Subtract p from this point
  point operator-(const point &p)
  {
    return {x - p.x, y - p.y};
  }
};

/**
 * Compute the area of an arbitrary polygon using Green's theorem
 *
 * Params:
 * - an array V of n (n>=3) vertices of the polygon, where each vertex is a position vector (x,y) in the Cartesian plane. The vertices should be ordered as they "appear" in the polygon.
 *
 * Output:
 * - The area of the polygon
*/
double green(vector<point> V)
{
  double area = 0;
  size_t n = V.size();

  for (size_t i = 0, j; i < n; i++)
  {
    j = (i + 1) % n;
    area += 0.5 * (V[j].x + V[i].x) * (V[j].y - V[i].y);
  }

  return area;
}

/**
 * Compute the area of an arbitrary polygon by exploiting the cross product formula
 *
 * Params:
 * - an array V of n (n>=3) vertices of the polygon, where each vertex is a position vector (x,y) in the Cartesian plane. The vertices should be ordered as they "appear" in the polygon.
 *
 * Output:
 * - The area of the polygon
*/
double crossproduct(vector<point> V)
{
  double area = 0, crossprodlength;

  // displacement vector V1 - V0
  point u1 = V[1] - V[0], u2;
  for (size_t i = 2; i < V.size(); i++)
  {
    // displacement vector Vi - V0
    u2 = V[i] - V[0];

    crossprodlength = abs((u1.x * u2.y) - (u1.y * u2.x));
    area += 0.5 * crossprodlength;

    u1 = u2;
  }
  return area;
}

int main()
{
  // Test drive
  vector<point> V{{{0, 3}, {3, 0}, {5, 1}, {4, 4}, {1, 5}}};

  // Print the polygon
  cout << "Polygon: { ";
  for (size_t i = 0; i < V.size(); i++)
  {
    cout << "(" << V[i].x << ", " << V[i].y << ")";
    if (i < V.size() - 1)
      cout << ", ";
  }
  cout << " }" << endl;
  cout << "Find its area:" << endl;
  cout << " Green's theorem: " << green(V) << endl;
  cout << " Cross product: " << crossproduct(V) << endl;

  return 0;
}