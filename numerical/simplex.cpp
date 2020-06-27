#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

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

int mostnegative(const vector<double> &v)
{
  auto smallest = min_element(v.begin(), v.end());
  return (*smallest < 0) ? distance(v.begin(), smallest) : -1;
}

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
    tableau[i].push_back(b[i]);

  // Copy objective coefficients and constant into tableau
  tableau.push_back(c);
  tableau[m].push_back(z0);

  return tableau;
}

bool update_basis(
    const vector<vector<double>> &tableau,
    size_t pivotcol,
    vector<size_t> &basis)
{
  size_t m = tableau.size() - 1, n = tableau[0].size() - 1;

  // Find the pivot row (and thus, the departing variable)
  size_t pivotrow;
  double theta_min = 1000000000;
  for (size_t i = 0; i < m; i++)
  {
    // Compute the theta ratio for each row and find the minimum
    double entry, theta;
    if ((entry = tableau[i][pivotcol]) > 0 &&
        (theta = tableau[i][n] / entry) < theta_min)
    {
      theta_min = theta;
      pivotrow = i;
    }
  }

  // Return false if no theta min was found
  if (theta_min == 1000000000)
    return false;

  // Update the basis
  basis[pivotrow] = pivotcol;

  return true;
}

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
    vector<size_t> &basis,
    double z0)
{
  // Initial tableau.
  auto tableau = create_tableau(A, b, c, z0);

  size_t m = A.size(); //, n = c.size();
  size_t pivotcol;

  // Repeat as long as there are negative coefficients in the objective row
  while ((pivotcol = mostnegative(tableau[m].begin(), tableau[m].end())) >= 0)
  {
    if (!update_basis(tableau, pivotcol, basis))
    {
      // The problem is unbounded. Return -infinity?
      return -1;
    }

    // TODO: Pivot!
    break;
  };
  return 0.0;
}

/* TESTS */

int main()
{
  // TEST mostnegative
  // vector<double> v{500, 75, 300, 0, 0, -9};
  // int mostnegativepos = mostnegative(v.begin(), v.end());
  // cout << "The most negative number is at " << mostnegativepos << endl;

  vector<vector<double>> A{{{1, 0, 0, 2, -1}, {0, 1, 0, -1, -5}, {0, 0, 1, 6, -12}}};
  vector<double> b{10, 20, 18};
  vector<double> c{0, 0, 0, -2, 3};
  vector<size_t> basis{0, 1, 2};
  double z0 = 60;

  simplex(A, b, c, basis, z0);

  for (auto &e : basis)
    cout << "x" << e + 1 << endl;

  // TEST create tableau
  // auto tableau = create_tableau(A, b, c, z0);

  // for (const auto &row : tableau)
  //   for (double e : row)
  //     cout << setw(4) << e;
  // cout << endl;

  return 0;
}