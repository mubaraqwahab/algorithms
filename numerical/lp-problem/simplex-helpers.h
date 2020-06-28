#include <vector>

/**
 * Returns the index of the most-negative number in a nonempty list (vector).
 * If there's no negative number, -1 is returned.
 *
 * Params:
 * - start, an iterator to the start of the list
 * - stop, an iterator to the element past-the-end of the list
 */
std::ptrdiff_t mostnegative(std::vector<double>::const_iterator start, std::vector<double>::const_iterator stop);

/**
 * Create a simplex tableau.
 *
 * Params:
 * - A, an m*n (m <= n) matrix of coefficients of the constraints.
 * - b, an m-dimensional (column) vector of constants of the constraints.
 * - c, an n-dimensional (row) vector of coefficients of the objective function.
 * - z0, the negative of the value of the objective function z.
 */
std::vector<std::vector<double>> create_tableau(const std::vector<std::vector<double>> &A,
                                                const std::vector<double> &b,
                                                const std::vector<double> &c,
                                                double z0);

/**
 * Compute the theta ratio of a tableau row.
 *
 * Params: a tableau row and the index of a pivot column.
 *
 * Output: the theta ratio (>=0) of the row. If the ratio < 0, -1 is returned.
 */
double theta_ratio(const std::vector<double> &tableaurow, std::size_t pivotcol);

/**
 * Determine the pivot row of a simplex tableau.
 *
 * Params:
 * - An (m+1)*(n+1) tableau. (m is the size of the basis, n is the number of variables)
 * - pivotcol, the index of the pivot column in the tableau
 *
 * Output:
 * - If there are no positive entries in pivot column, return -1.
 * - Otherwise, return the index of the pivot row.
 */
std::ptrdiff_t find_pivot_row(const std::vector<std::vector<double>> &tableau, std::size_t pivotcol);

/**
 * Pivots a matrix.
 *
 * Params:
 * - m by n matrix A
 * - the index of the pivot row (0 <= pivotrow < m)
 * - the index of the pivot column (0 <= pivotcol < n)
 *
 * Output: matrix A reduced to canonical form. (Nothing is returned.)
 */
void pivot(std::vector<std::vector<double>> &A, std::size_t pivotrow, std::size_t pivotcol);

/**
 * Given a simplex tableau and its basis, return (a vector of) the basic solution.
 */
std::vector<double> get_tableau_solution(const std::vector<std::vector<double>> &tableau,
                                         const std::vector<std::size_t> &basis);
