#include <vector>

/**
 * Returns the index of the most-negative number in a nonempty list (vector).
 * If there's no negative number, -1 is returned.
 *
 * Params:
 * - start, an iterator to the start of the list
 * - stop, an iterator to the element past-the-end of the list
 */
std::ptrdiff_t mostnegative(
    std::vector<double>::const_iterator start,
    std::vector<double>::const_iterator stop);