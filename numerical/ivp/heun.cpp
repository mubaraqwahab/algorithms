#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Solve the initial-value problem dy/dt = f(t,y), a<=t<=b, y0=y(a)
 * using Heun's method.
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
double heun(double f(double, double), double y0, double a, double b, double h)
{
  double w = y0, z;

  for (double t = a; t < b; t += h)
  {
    // Euler's predictor
    z = w + h * f(t, w);

    w = w + (h / 2) * (f(t, w) + f(t + h, z));
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

  cout << "Solve the IVP dy/dt = -2y + 5t, y(0) = 2, 0<=t<=1 using Heun's method:" << endl;
  cout << "Solution: At t = " << b << ", y = " << setiosflags(ios::fixed) << setprecision(6)
       << heun(f, y0, a, b, h) << endl;
  return 0;
}
