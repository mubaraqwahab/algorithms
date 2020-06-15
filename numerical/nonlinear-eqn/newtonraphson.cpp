#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Solve, using Newton-Raphson method, f(x)=0 on some interval [a,b].
 *
 * Params:
 * - A continuous (and twice-differentiable) function f(x) on [a,b],
 * - g(x), the derivative of f(x),
 * - An initial approximation z0 (z0 in [a,b]) to the root of f(x)=0,
 * - An error tolerance, tol,
 * - max_iter, the maximum number of iterations allowed.
 *
 * Ouput: An approximation to the root of f(x)=0.
 */
double newtonraphson(double f(double), double g(double), double z0, double tol, int max_iter);

/* f(x) = x^3 + 2x^2 - 5 */
double f(double x)
{
  return (x * x * x) + (2 * x * x) - 5;
}

/* g(x) = 3x^2 + 4x */
double g(double x)
{
  return (3 * x * x) + (4 * x);
}

int main()
{
  // Test
  double z0 = 1.5;
  double tol = 1e-4;
  int max_iter = 20;

  cout << "Solve x^3 + 2x^2 - 5 = 0 on [1,2] correct to within 1e-4 using Newton-Raphson method:" << endl;
  cout << "Solution: x = " << setiosflags(ios::fixed) << setprecision(6)
       << newtonraphson(f, g, z0, tol, max_iter) << endl;
}

double newtonraphson(double f(double), double g(double), double z0, double tol, int max_iter)
{
  double z, error;
  int i = 0;

  do
  {
    z = z0 - (f(z0) / g(z0));

    error = abs(z - z0);
    i++;

    z0 = z;
  } while (i < max_iter && error > tol);

  return z;
}