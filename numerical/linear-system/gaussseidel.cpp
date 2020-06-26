#include <iostream>
#include <iomanip>
#include <vector>
// #include "norm.h"

using namespace std;

vector<double> gaussseidel(const vector<vector<double>> &A,
                           const vector<double> &b,
                           const vector<double> &x0,
                           double tol, size_t max_iter)
{
  vector<double> x{x0};
  size_t n = x.size(), k = 0;

  do
  {
    for (size_t i = 0; i < n; i++)
    {
      x[i] = b[i];
      for (size_t j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        x[i] -= A[i][j] * x[j];
      }
      x[i] /= A[i][i];
    }
  } while (++k < max_iter);

  return x;
}

int main()
{
  vector<vector<double>> A{{{4, -1, 1}, {4, -8, 1}, {-2, 1, 5}}};
  vector<double> b{7, -21, 15};

  vector<double> x0{1, 2, 2};

  double tol = 1e-2;
  size_t max_iter = 10;
  vector<double> x = gaussseidel(A, b, x0, tol, max_iter);

  for (const auto &x : x)
  {
    cout << setw(12) << setiosflags(ios::fixed) << setprecision(8) << x;
  }

  cout << endl;

  return 0;
}