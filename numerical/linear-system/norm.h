#include <vector>

using namespace std;

/**
 * Compute the Taxicab norm of two n-dimensional vectors.
 *
 * Params:
 * - n-dimensional vectors u and v
 *
 * Output: the Taxicab norm of u and v.
 */
double taxicab_norm(const vector<double> &u, const vector<double> &v);

/**
 * Compute the max norm of two n-dimensional vectors.
 *
 * Params:
 * - n-dimensional vectors u and v
 *
 * Output: the max norm of u and v.
 */
double max_norm(const vector<double> &u, const vector<double> &v);

/**
 * Compute the Euclidean norm of two n-dimensional vectors.
 *
 * Params:
 * - n-dimensional vectors u and v
 *
 * Output: the Euclidean norm of u and v.
 */
double euclid_norm(const vector<double> &u, const vector<double> &v);