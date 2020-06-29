#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

/* CREATE TABLEAU */

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

/* THETA RATIO */

double theta_ratio(const vector<double> &tableaurow, size_t pivotcol)
{
  double entry;

  // Find the ratio only for a nonnegative entry
  if ((entry = tableaurow[pivotcol]) > 0)
  {
    size_t n = tableaurow.size() - 1;
    return tableaurow[n] / entry;
  }

  return -1;
}

/* FIND PIVOT ROW */

ptrdiff_t find_pivot_row(const vector<vector<double>> &tableau, size_t pivotcol)
{
  size_t m = tableau.size() - 1;
  size_t pivotrow;

  // Compute the theta ratio for each row and find the minimum
  double theta_min = numeric_limits<double>::infinity();
  for (size_t i = 0; i < m; i++)
  {
    double theta = theta_ratio(tableau[i], pivotcol);

    if (theta < 0 || theta >= theta_min)
      continue;

    theta_min = theta;
    pivotrow = i;
  }

  // No theta min was found
  if (theta_min == numeric_limits<double>::infinity())
    return -1;

  return pivotrow;
}

/* GET TABLEAU SOLUTION */

vector<double> get_tableau_solution(
    const vector<vector<double>> &tableau,
    const vector<size_t> &basis)
{
  size_t n = tableau[0].size() - 1;
  vector<double> solution(n);

  // Find the values of basic variables in the tableau
  // (nonbasic variables are set to 0)
  for (size_t i = 0; i < n; i++)
  {
    auto it = find(basis.begin(), basis.end(), i);
    if (it != basis.end())
    {
      size_t row = distance(basis.begin(), it);
      solution[i] = tableau[row][n];
    }
  }

  return solution;
}