#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

/**
 * Returns the index of the most-negative number in a nonempty list (vector).
 * If there's no negative number, -1 is returned.
 *
 * Params:
 * - start, an iterator to the start of the list
 * - stop, an iterator to the element past-the-end of the list
 */
int mostnegative(vector<double>::const_iterator start, vector<double>::const_iterator stop)
{
  auto smallest = min_element(start, stop);
  return (*smallest < 0) ? distance(start, smallest) : -1;
}

double simplex(const vector<vector<double>> &A,
               const vector<double> &b,
               const vector<double> &c,
               double z0,
               vector<double> &basis)
{

  return 0.0;
}

int main()
{
  vector<double> v{500, 75, 300, 0, 0, -9};

  int mostnegativepos = mostnegative(v.begin(), v.end());
  cout << "The most negative number is at " << mostnegativepos << endl;

  return 0;
}