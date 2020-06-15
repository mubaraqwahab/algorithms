#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Solve, using fixed-point iteration, x=g(x) on some interval [a,b].
 *
 * Params:
 * - The function g(x) that satisfies the Fixed-Point Theorem on [a,b],
 * - An initial approximation p0 (p0 in [a,b]) to the fixed point of g(x),
 * - An error tolerance, tol
 * - The maximum number of iterations allowed.
 *
 * Ouput: An approximation to the solution to x=g(x).
 */
double fixedpoint(double g(double), double p0, double tol, double max_iter);

/* g(x) = (3x^2 + 3)^(1/4) */
double g(double x)
{
  return pow(3 * x * x + 3, 0.25);
}

int main()
{
  // Test
  double p0 = 1;
  double tol = 1e-2;
  int max_iter = 20;

  cout << "Solve x = (3x^2 + 3)^(1/4) correct to within 1e-2 using fixed-point iteration:" << endl;
  cout << "Solution: x = " << setiosflags(ios::fixed) << setprecision(6)
       << fixedpoint(g, p0, tol, max_iter) << endl;
}

double fixedpoint(double g(double), double p0, double tol, double max_iter)
{
  double p, error, i = 1;

  do
  {
    p = g(p0);

    error = std::abs(p - p0);
    i++;

    p0 = p;
  } while (i < max_iter && error > tol);

  // Why does the error get printed without the return statement?
  // return p;
}