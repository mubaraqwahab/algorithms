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
ssize_t mostnegative(vector<double>::const_iterator start, vector<double>::const_iterator stop)
{
  auto smallest = min_element(start, stop);
  return (*smallest < 0) ? distance(start, smallest) : -1;
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

/**
 * Update the basis of a simplex tableau.
 *
 * Params:
 * - An (m+1)*(n+1) tableau. (m is the size of the basis, n is the number of variables)
 * - pivotcol, the index of the pivot column in the tableau
 * - An m-dimensional basis.
 *
 * Output:
 * - If there are no positive entries in pivot column, return -1.
 * - Otherwise, update the basis parameter and return the index of the pivot row.
 */
ssize_t update_basis(const vector<vector<double>> &tableau, size_t pivotcol, vector<size_t> &basis)
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

  // No theta min was found
  if (theta_min == 1000000000)
    return -1;

  // Update the basis
  basis[pivotrow] = pivotcol;

  return pivotrow;
}

/**
 * Pivots a matrix.
 *
 * Params:
 * - m by n matrix A
 * - the index of the pivot row (0 <= pivotrow < m)
 * - the index of the pivot column (0 <= pivotcol < n)
 *
 * Output: matrix A reduced to canonical form. (Nothing is returned.)
 */
void pivot(vector<vector<double>> &A, size_t pivotrow, size_t pivotcol)
{
  double pivot = A[pivotrow][pivotcol];
  size_t m = A.size(), n = A[0].size();

  // Divide the pivot row by the pivot
  for (size_t j = 0; j < n; j++)
  {
    A[pivotrow][j] /= pivot;
  }

  // Subtract other rows from the pivot row
  for (size_t i = 0; i < m; i++)
  {
    if (i == pivotrow)
      continue;

    double multiplier = A[i][pivotcol];
    for (size_t j = 0; j < n; j++)
    {
      A[i][j] -= multiplier * A[pivotrow][j];
    }
  }
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
 * Output: An optimal solution to the LP problem is returned.
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

  size_t m = A.size(), n = c.size();
  ssize_t pivotcol;

  // Repeat as long as there are negative coefficients in the objective row
  while ((pivotcol = mostnegative(tableau[m].begin(), tableau[m].end() - 1)) != -1)
  {
    ssize_t pivotrow = update_basis(tableau, pivotcol, basis);
    if (pivotrow == -1)
    {
      // The problem is unbounded. Return -infinity?
      return -1000000000;
    }

    // TODO: Pivot!
    break;
  }

  return -tableau[m][n];
}

/* TESTS */

void print2darr(const vector<vector<double>> &A)
{
  for (const auto &row : A)
  {
    for (double e : row)
    {
      cout << setw(8) << setprecision(3) << e;
    }
    cout << endl;
  }
}

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

  // TEST simplex
  // cout << "z = " << simplex(A, b, c, basis, z0) << endl;
  // for (auto &e : basis)
  //   cout << "x" << e + 1 << endl;

  // TEST create tableau
  // auto tableau = create_tableau(A, b, c, z0);
  // cout << "Before pivot" << endl;
  // print2darr(tableau);

  // TEST pivot
  // pivot(tableau, 2, 3);
  // cout << "After pivot" << endl;
  // print2darr(tableau);

  return 0;
}