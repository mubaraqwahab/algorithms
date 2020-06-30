#include <vector>
#include <algorithm> // min_element, distance

using namespace std;

/* MOST NEGATIVE */

int mostnegative(vector<double>::const_iterator start, vector<double>::const_iterator stop)
{
  auto smallest = min_element(start, stop);
  return (*smallest < 0) ? distance(start, smallest) : -1;
}