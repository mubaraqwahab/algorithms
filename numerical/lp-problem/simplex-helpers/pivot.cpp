#include <vector>

using namespace std;

/* PIVOT */

void pivot(vector<vector<double>> &A, int pivotrow, int pivotcol)
{
  double pivot = A[pivotrow][pivotcol];
  int m = A.size(), n = A[0].size();

  // Divide the pivot row by the pivot
  for (int j = 0; j < n; j++)
  {
    A[pivotrow][j] /= pivot;
  }

  // Subtract other rows from the pivot row
  for (int i = 0; i < m; i++)
  {
    if (i == pivotrow)
      continue;

    double multiplier = A[i][pivotcol];
    for (int j = 0; j < n; j++)
    {
      A[i][j] -= multiplier * A[pivotrow][j];
    }
  }
}
