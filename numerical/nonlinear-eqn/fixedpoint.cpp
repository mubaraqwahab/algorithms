#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Solve, using fixed-point iteration, x=g(x) on some interval [a,b].
 *
 * Params:
 * - A function g(x) that satisfies the Fixed-Point Theorem on [a,b],
 * - An initial approximation p0 (p0 in [a,b]) to the fixed point of g(x),
 * - An error tolerance, tol,
 * - max_iter, the maximum number of iterations allowed.
 *
 * Ouput: An approximation to the solution to x=g(x).
 */
double fixedpoint(double g(double), double p0, double tol, size_t max_iter)
{
  double p, error;
  size_t i = 0;

  do
  {
    p = g(p0);

    error = abs(p - p0);
    i++;

    p0 = p;
  } while (i < max_iter && error > tol);

  return p;
}

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
  size_t max_iter = 20;

  cout << "Solve x = (3x^2 + 3)^(1/4) correct to within 1e-2 using fixed-point iteration:" << endl;
  cout << "Solution: x = " << setiosflags(ios::fixed) << setprecision(6)
       << fixedpoint(g, p0, tol, max_iter) << endl;
}
