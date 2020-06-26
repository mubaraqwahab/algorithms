#include <vector>
#include <cmath>

using namespace std;

double taxicab_norm(const vector<double> &u, const vector<double> &v)
{
  double norm = 0;
  for (size_t i = 0; i < u.size(); i++)
  {
    norm += abs(u[i] - v[i]);
  }
  return norm;
}

double max_norm(const vector<double> &u, const vector<double> &v)
{
  double norm = 0, r;
  for (size_t i = 0; i < u.size(); i++)
  {
    r = abs(u[i] - v[i]);
    if (r > norm)
    {
      norm = r;
    }
  }
  return norm;
}

double euclid_norm(const vector<double> &u, const vector<double> &v)
{
  double norm = 0;
  for (size_t i = 0; i < u.size(); i++)
  {
    norm += pow(u[i] - v[i], 2);
  }
  return sqrt(norm);
}