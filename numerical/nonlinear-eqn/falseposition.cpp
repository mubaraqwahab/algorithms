#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Solve, using the method of false position (regula falsi), f(x)=0 on some interval [a,b].
 *
 * Params:
 * - A continuous function f(x) on [a,b] that changes sign on the interval,
 * - a and b, the endpoints of the interval.
 * - An error tolerance, tol,
 * - max_iter, the maximum number of iterations allowed.
 *
 * Ouput: An approximation to the root of f(x)=0 on [a,b].
 */
double falseposition(double f(double), double a, double b, double tol, size_t max_iter)
{
  double c, ya = f(a), yb = f(b), yc;

  for (size_t i = 0; i < max_iter; i++)
  {
    c = (yb * a - ya * b) / (yb - ya);
    yc = f(c);

    if (ya * yc < 0)
    {
      b = c;
      yb = yc;
    }
    else if (yc * yb < 0)
    {
      a = c;
      ya = yc;
    }
    else
      break;

    if (b - a <= tol)
      break;
  }

  return c;
}

/* f(x) = ln(x+1) - cos(x) */
double f(double x)
{
  return log(x + 1) - cos(x);
}

int main()
{
  // Test
  double a = 0, b = 2;
  double tol = 1e-2;
  size_t max_iter = 20;

  cout << "Solve ln(x+1) - cos(x) = 0 on [0,2] correct to within 1e-2 using the method of false position:" << endl;
  cout << "Solution: x = " << setiosflags(ios::fixed) << setprecision(6)
       << falseposition(f, a, b, tol, max_iter) << endl;
  // Solution should be x = 0.884511

  return 0;
}
