#include <vector>

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