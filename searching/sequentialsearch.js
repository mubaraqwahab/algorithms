/**
 * Find the position of the first element in `array` from `start` position to `stop`
 * that satisfies `predicate` using sequential search.
 * Return -1 if no element satisfies `predicate`.
 * @param {array} array - an array to search.
 * @param {function(T): boolean} predicate - a predicate function.
 * When called on an element, if it returns a truthy value, then the search succeeds.
 * @param {number} [start] - an index of `array` to start searching from. Defaults to 0.
 * @param {number} [stop] - an index of `array` to stop at.
 * The element at this position is not searched. Defaults to the length of `array`.
 */
export function sequentialSearch(
  array,
  predicate,
  start = 0,
  stop = array.length
) {
  for (let i = start; i < stop; i++) {
    if (predicate(array[i])) {
      return i;
    }
  }
  return -1;
}
