#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include "simplex.h"
#include "simplex-helpers/mostnegative.h"
#include "simplex-helpers/tableau.h"
#include "simplex-helpers/pivot.h"

#define PRECISION 6

using namespace std;

/* TESTS */

void test_mostnegative(const vector<double> &v);

vector<vector<double>> test_createtableau(
    const vector<vector<double>> &A,
    const vector<double> &b,
    const vector<double> &c,
    double z0);

void test_pivot(vector<vector<double>> &A, int pivotrow, int pivotcol);

void test_simplex(
    const vector<vector<double>> &A,
    const vector<double> &b,
    const vector<double> &c,
    vector<int> &basis,
    double z0);

void print_array(const vector<double> &arr, bool newline);
void print_row(const vector<double> &v);
void print_table(const vector<vector<double>> &A);

int main()
{
  cout << "Solve the LP Problem in canonical form (with basic variables x4, x5 and x6):" << endl
       << "Minimize z = -700 x1 - 750 x2 - 550 x3" << endl
       << "subject to:    25 x1 +  30 x2 +  20 x3 + x4           = 2400" << endl
       << "               15 x1 +  15 x2 +  10 x3      + x5      = 1260" << endl
       << "                - x1 -     x2 +   4 x3           + x6 = 0" << endl
       << "               x1, x2, x3, x4, x5, x6 >= 0." << endl;

  // Constraint coefficients
  vector<vector<double>> A{{{25, 30, 20, 1, 0, 0},
                            {15, 15, 10, 0, 1, 0},
                            {-1, -1, 4, 0, 0, 1}}};
  // Constraint constants
  vector<double> b{2400, 1260, 0};
  // Coefficients of objective function z
  vector<double> c{-700, -750, -550, 0, 0, 0};
  // Indices of basic variables
  vector<int> basis{3, 4, 5};
  // Negative of the value z at the basis
  double z0 = 0;

  // TEST simplex
  cout << endl;
  test_simplex(A, b, c, basis, z0);

  /* OTHER TESTS... */

  // TEST mostnegative
  // vector<double> v{500, 75, 300, 0, 0, -9};
  // test_mostnegative(v);

  // TEST create tableau
  // auto tableau = test_createtableau(A, b, c, z0);

  // TEST pivot
  // test_pivot(tableau, 0, 1);

  return 0;
}

void test_mostnegative(const vector<double> &v)
{
  cout << "\nMOST NEGATIVE TEST" << endl;
  cout << "Given ";
  print_array(v, false);
  cout << ". ";

  int mostnegativepos = mostnegative(v.begin(), v.end());
  if (mostnegativepos == -1)
    cout << "There's no negative number" << endl;
  else
    cout << "The most negative number is at index " << mostnegativepos << endl;
}

vector<vector<double>> test_createtableau(
    const vector<vector<double>> &A,
    const vector<double> &b,
    const vector<double> &c,
    double z0)
{
  auto tableau = create_tableau(A, b, c, z0);
  cout << "\nTEST CREATE TABLEAU" << endl;
  cout << "Created Tableau:" << endl;
  print_table(tableau);
  return tableau;
}

void test_pivot(vector<vector<double>> &A, int pivotrow, int pivotcol)
{
  cout << "\nPIVOT TEST" << endl;
  cout << "Before pivot:" << endl;
  print_table(A);
  pivot(A, pivotrow, pivotcol);
  cout << "After pivot at row " << pivotrow + 1 << ", col " << pivotcol + 1 << ":" << endl;
  print_table(A);
}

void test_simplex(
    const vector<vector<double>> &A,
    const vector<double> &b,
    const vector<double> &c,
    vector<int> &basis,
    double z0)
{
  double z;
  vector<double> solution;
  tie(z, solution) = simplex(A, b, c, basis, z0);

  if (z != -numeric_limits<double>::infinity())
  {
    cout << "SIMPLEX METHOD TEST" << endl;
    cout << "Solution: z has an optimum value of " << z << " at ";
    print_array(solution, true);
  }
  else
  {
    cout << "The LP problem is unbounded below." << endl;
  }
}

void print_array(const vector<double> &arr, bool newline)
{
  int i = 0;
  cout << "(";

  for (; i < arr.size() - 1; i++)
    cout << setprecision(PRECISION) << arr[i] << ", ";
  cout << setprecision(PRECISION) << arr[i] << ")";

  if (newline)
    cout << endl;
}

void print_row(const vector<double> &v)
{
  for (double e : v)
    cout << setw(10) << setprecision(PRECISION) << e;
  cout << endl;
}

void print_table(const vector<vector<double>> &A)
{
  for (const auto &row : A)
    print_row(row);
}