/**
 * Sort an array by quicksort.
 * @param {Array<T>} array - An array to sort.
 * @param {function(T,T): number} compare - A comparison function.
 * When called with any two values `a` and `b` of an array,
 * if it returns a positive number, then `b` precedes `a` in the sorted array.
 * Otherwise `a` precedes `b`.
 * @param {number} [left]
 * @param {number} [right]
 */
export function quicksort(array, compare, left = 0, right = array.length - 1) {
  if (left < right) {
    const splitPos = partition(array, compare, left, right);
    quicksort(array, compare, left, splitPos - 1);
    quicksort(array, compare, splitPos + 1, right);
  }
}

/**
 * Partition an array by Hoare's algorithm, using the first element as a pivot.
 * @param {Array<T>} array
 * @param {function(T,T): number} compare
 * @param {number} left
 * @param {number} right
 */
function partition(array, compare, left, right) {
  const pivot = array[left];

  let i = left, j = right + 1;

  do {
    do i++;
    while (i < right && compare(array[i], pivot) < 0);

    do j--;
    while (compare(array[j], pivot) > 0);

    if (i < j) {
      // Swap array[i] and array[j]
      [array[i], array[j]] = [array[j], array[i]];
    }
  } while (i < j);

  // Swap pivot and array[j]
  [array[left], array[j]] = [array[j], array[left]];
  return j;
}
