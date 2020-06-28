#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <utility> // pair
#include "simplex-helpers.h"

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

  /**
   * Solve the LP Problem in canonical form:
   * Minimize z = -700 x1 - 750 x2 - 550 x3
   * subject to:    25 x1 +  30 x2 +  20 x3 + x4           = 2400
   *                15 x1 +  15 x2 +  10 x3      + x5      = 1260
   *                 - x1 -     x2 +   4 x3           + x6 = 0
   *                x1, x2, x3, x4, x5, x6 >= 0.
   */

  // Constraint coefficients
  vector<vector<double>> A{{{25, 30, 20, 1, 0, 0},
                            {15, 15, 10, 0, 1, 0},
                            {-1, -1, 4, 0, 0, 1}}};
  // Constraint constants
  vector<double> b{2400, 1260, 0};
  // Coefficients of objective function z
  vector<double> c{-700, -750, -550, 0, 0, 0};
  // Indices of basic variables
  vector<size_t> basis{3, 4, 5};
  // Negative of the value z at the basis
  double z0 = 0;

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

pair<double, vector<double>> simplex(const vector<vector<double>> &A,
                                     const vector<double> &b,
                                     const vector<double> &c,
                                     vector<size_t> &basis,
                                     double z0)
{
  // Initial tableau.
  auto tableau = create_tableau(A, b, c, z0);

  size_t m = A.size(), n = c.size();
  ptrdiff_t pivotcol;

  // Repeat as long as there are negative coefficients in the objective row
  while ((pivotcol = mostnegative(tableau[m].begin(), tableau[m].end() - 1)) != -1)
  {
    ptrdiff_t pivotrow = find_pivot_row(tableau, pivotcol);
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