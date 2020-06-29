#include <vector>

using namespace std;

/* PIVOT */

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
