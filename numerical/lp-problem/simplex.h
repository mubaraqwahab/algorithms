#include <vector>
#include <utility> // pair

/**
 * Solve a linear programming (LP) problem in canonical form using the Simplex method.
 *
 * Params:
 * - A, an m*n (m <= n) matrix of coefficients of the constraints.
 * - b, an m-dimensional (column) vector of constants of the constraints.
 * - c, an n-dimensional (row) vector of coefficients of the objective function.
 * - basis, an m-dimensional (column) vector of the indices i (0<=i<n) of the basic variables.
 * - z0, the negative of an initial value of the objective function z.
 *
 * Output:
 * - If the LP problem has an optimal solution, a pair (z, p) is returned,
 *    where p (a vector) is an optimal solution and
 *    z is the value of the objective function at that point.
 *    The basis parameter is also modified to be the basis at that solution.
 * - If the problem is unbounded, a pair (-∞, q), where q is an empty vector, is returned.
 */
std::pair<double, std::vector<double>> simplex(
    const std::vector<std::vector<double>> &A,
    const std::vector<double> &b,
    const std::vector<double> &c,
    std::vector<std::size_t> &basis,
    double z0);