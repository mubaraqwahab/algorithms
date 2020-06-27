#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

/**
 * Returns the index of the most-negative number in a nonempty list (vector).
 * If there's no negative number, -1 is returned.
 *
 * Params:
 * - start, an iterator to the start of the list
 * - stop, an iterator to the element past-the-end of the list
 */
ssize_t mostnegative(vector<double>::const_iterator start, vector<double>::const_iterator stop);

/**
 * Create a simplex tableau.
 *
 * Params:
 * - A, an m*n (m <= n) matrix of coefficients of the constraints.
 * - b, an m-dimensional (column) vector of constants of the constraints.
 * - c, an n-dimensional (row) vector of coefficients of the objective function.
 * - z0, the negative of the value of the objective function z.
 */
vector<vector<double>> create_tableau(const vector<vector<double>> &A,
                                      const vector<double> &b,
                                      const vector<double> &c,
                                      double z0);

/**
 * Determine the pivot row of a simplex tableau.
 *
 * Params:
 * - An (m+1)*(n+1) tableau. (m is the size of the basis, n is the number of variables)
 * - pivotcol, the index of the pivot column in the tableau
 *
 * Output:
 * - If there are no positive entries in pivot column, return -1.
 * - Otherwise, return the index of the pivot row.
 */
ssize_t find_pivot_row(const vector<vector<double>> &tableau, size_t pivotcol);

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
void pivot(vector<vector<double>> &A, size_t pivotrow, size_t pivotcol);

/**
 * Given a simplex tableau and its basis, return (a vector of) the basic solution.
 */
vector<double> get_tableau_solution(const vector<vector<double>> &tableau, const vector<size_t> &basis);

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
 * Output:
 * - If the LP problem has an optimal solution, a pair (z, p) is returned,
 *    where p (a vector) is an optimal solution and
 *    z is the value of the objective function at that point.
 *    The basis parameter is also modified to be the basis at that solution.
 * - If the problem is unbounded, a pair (-∞, q), where q is an empty vector, is returned.
 */
pair<double, vector<double>> simplex(const vector<vector<double>> &A,
                                     const vector<double> &b,
                                     const vector<double> &c,
                                     vector<size_t> &basis,
                                     double z0);

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
  double z;
  vector<double> solution;
  tie(z, solution) = simplex(A, b, c, basis, z0);

  if (z != -numeric_limits<double>::infinity())
  {
    cout << "Solution: z has an optimum value of " << z << " at (";
    size_t i = 0;
    for (; i < solution.size() - 1; i++)
    {
      cout << setprecision(4) << solution[i] << ", ";
    }
    cout << setprecision(4) << solution[i] << ")." << endl;
  }
  else
  {
    cout << "The LP problem is unbounded below." << endl;
  }

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

/* DEFINITIONS */

ssize_t mostnegative(vector<double>::const_iterator start, vector<double>::const_iterator stop)
{
  auto smallest = min_element(start, stop);
  return (*smallest < 0) ? distance(start, smallest) : -1;
}

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

ssize_t find_pivot_row(const vector<vector<double>> &tableau, size_t pivotcol)
{
  size_t m = tableau.size() - 1, n = tableau[0].size() - 1;

  // Find the pivot row (and thus, the departing variable)
  size_t pivotrow;
  double theta_min = numeric_limits<double>::infinity();
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
  if (theta_min == numeric_limits<double>::infinity())
    return -1;

  return pivotrow;
}

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

vector<double> get_tableau_solution(const vector<vector<double>> &tableau, const vector<size_t> &basis)
{
  size_t n = tableau[0].size() - 1;
  vector<double> solution(n);

  for (size_t i = 0; i < n; i++)
  {
    auto it = find(basis.begin(), basis.end(), i);
    if (it != basis.end())
    {
      size_t pos = distance(basis.begin(), it);
      solution[i] = tableau[pos][n];
    }
  }

  return solution;
}

pair<double, vector<double>> simplex(
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
    ssize_t pivotrow = find_pivot_row(tableau, pivotcol);
    if (pivotrow == -1)
    {
      // The problem is unbounded.
      return make_pair(-numeric_limits<double>::infinity(), vector<double>{});
    }

    // Update the basis
    basis[pivotrow] = pivotcol;

    pivot(tableau, pivotrow, pivotcol);
  }

  auto solution = get_tableau_solution(tableau, basis);

  return make_pair(-tableau[m][n], solution);
}