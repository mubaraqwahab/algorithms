#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Solve, using secant method, f(x)=0 on some interval [a,b].
 *
 * Params:
 * - A continuous (and twice-differentiable) function f(x) on [a,b],
 * - Two initial approximations z0 and z1 (z0, z1 in [a,b]) to the root of f(x)=0,
 * - An error tolerance, tol,
 * - max_iter, the maximum number of iterations allowed.
 *
 * Ouput: An approximation to the root of f(x)=0.
 */
double secant(double f(double), double z0, double z1, double tol, int max_iter)
{
  double z2, y0 = f(z0), y1;

  for (int i = 0; i < max_iter; i++)
  {
    y1 = f(z1);
    z2 = (y1 * z0 - y0 * z1) / (y1 - y0);

    if (abs(z2 - z1) <= tol)
      break;

    z0 = z1;
    y0 = y1;
    z1 = z2;
  }

  return z2;
}

/* f(x) = x^3 + 2x^2 - 5 */
double f(double x)
{
  return (x * x * x) + (2 * x * x) - 5;
}

int main()
{
  // Test
  double z0 = 1.5, z1 = 1.6;
  double tol = 1e-4;
  int max_iter = 20;

  cout << "Solve x^3 + 2x^2 - 5 = 0 on [1,2] correct to within 1e-4 using secant method:" << endl;
  cout << "Solution: x = " << setiosflags(ios::fixed) << setprecision(6)
       << secant(f, z0, z1, tol, max_iter) << endl;
  // Solution should be 1.241897

  return 0;
}
