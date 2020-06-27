#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

/**
 * Solve a linear programming (LP) problem in canonical form using the Simplex method.
 *
 * Params:
 * - A, an m*n (m <= n) matrix of coefficients of the constraints.
 * - b, an m-dimensional (column) vector of constants of the constraints.
 * - c, an n-dimensional (row) vector of coefficients of the objective function.
 * - basis, an m-dimensional (column) vector of the indices i (0<=i<n) of the basic variables.
 * - z0, the negative of an initial value of the objective function z.
 *
 * Output: An optimal solution of the LP problem is returned.
 * The basis parameter is also modified to be the basis at that solution.
 */
double simplex(
    const vector<vector<double>> &A,
    const vector<double> &b,
    const vector<double> &c,
    vector<double> &basis,
    double z0)
{
  return 0.0;
}

/* HELPERS */

/**
 * Create a simplex tableau.
 *
 * Params:
 * - A, an m*n (m <= n) matrix of coefficients of the constraints.
 * - b, an m-dimensional (column) vector of constants of the constraints.
 * - c, an n-dimensional (row) vector of coefficients of the objective function.
 * - z0, the negative of the value of the objective function z.
 */
vector<vector<double>> create_tableau(
    const vector<vector<double>> &A,
    const vector<double> &b,
    const vector<double> &c,
    double z0)
{
  size_t m = A.size();

  // Copy the constraint coefficients into tableau
  vector<vector<double>> tableau = A;

  // Copy constraint constants into tableau
  for (size_t i = 0; i < m; i++)
  {
    tableau[i].push_back(b[i]);
  }

  // Copy objective coefficients and constant into tableau
  tableau.push_back(c);
  tableau[m].push_back(z0);

  return tableau;
}

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

/* TESTS */

int main()
{
  // TEST mostnegative
  // vector<double> v{500, 75, 300, 0, 0, -9};
  // int mostnegativepos = mostnegative(v.begin(), v.end());
  // cout << "The most negative number is at " << mostnegativepos << endl;

  vector<vector<double>> A{{{1, 0, 2, -1}, {0, 1, -1, -5}}};
  vector<double> b{10, 20};
  vector<double> c{0, 0, 2, -3};
  double z0 = 60;

  // TEST create tableau
  auto tableau = create_tableau(A, b, c, z0);

  for (const auto &row : tableau)
  {
    for (double e : row)
    {
      cout << setw(4) << e;
    }
    cout << endl;
  }

  return 0;
}