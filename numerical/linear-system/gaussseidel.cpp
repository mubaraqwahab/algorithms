#include <iostream>
#include <iomanip>
#include <vector>
#include "norm.h"

using namespace std;

/**
 * Solve the system of linear equations Ax = b using Gauss-Seidel iteration.
 *
 * Params:
 * - The matrix of coefficients A of the system.
 * - The vector of constants b
 * - x0, an initial guess to the solution
 * - An error tolerance tol
 * - The maximum number of iterations, max_iter
 *
 * Output: An approximation to the solution to the system Ax = b.
 */
vector<double> gaussseidel(const vector<vector<double>> &A,
                           const vector<double> &b,
                           vector<double> x0,
                           double tol, size_t max_iter)
{
  vector<double> x{x0};
  size_t n = x.size();

  for (size_t k = 0; k < max_iter; k++)
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

    if (max_norm(x, x0) <= tol)
      break;

    x0 = x;
  }

  return x;
}

int main()
{
  vector<vector<double>> A{{{4, -2, -2, 0},
                            {-2, 5, 1, -2},
                            {-2, 1, 10, 3},
                            {0, -2, 3, 18}}};
  vector<double> b{4, -4, 4, -13};

  vector<double> x0{0, 0, 0, 0};
  double tol = 1e-2;
  size_t max_iter = 10;

  vector<double> x = gaussseidel(A, b, x0, tol, max_iter);

  cout << "Gauss-Seidel iteration solution" << endl;
  for (const auto &a : x)
  {
    cout << setw(10) << setiosflags(ios::fixed) << setprecision(6) << a;
  }
  cout << endl;

  // Solution should be (1.001612, -0.999459, 1.000227, -0.999978)

  return 0;
}