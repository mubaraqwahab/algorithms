#include <vector>
#include <limits>
#include <utility> // pair
#include "simplex-helpers/mostnegative.h"
#include "simplex-helpers/pivot.h"
#include "simplex-helpers/tableau.h"

using namespace std;

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