#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Solve the initial-value problem dy/dt = f(t,y), a<=t<=b, y0=y(a)
 * using Euler's method
 *
 * Params:
 * - f(t,y), the derivative of y with respect to t
 * - y0, an initial value of y (i.e. the value of y at t=a)
 * - a, an initial value of t (or the lower endpoint)
 * - b, a final value of t (or the higher endpoint)
 * - h, a step size
 *
 * Output: An approximation to y(b)
 */
double euler(double f(double, double), double y0, double a, double b, double h)
{
  double w = y0;

  for (double t = a; t < b; t += h)
  {
    w = w + h * f(t, w);
  }

  return w;
}

// f(t,y) = -2y + 5t
double f(double t, double y)
{
  return -2 * y + 5 * t;
}

int main()
{
  // Test
  double a = 0, b = 1;
  double y0 = 2;
  double h = 0.25;

  cout << "Solve the IVP dy/dt = -2y + 5t, y(0) = 2, 0<=t<=1 using Euler's method:" << endl;
  cout << "Solution: At t = " << b << ", y = " << setiosflags(ios::fixed) << setprecision(6)
       << euler(f, y0, a, b, h) << endl;
  return 0;
}
