/**
 * Sort an array by selection sort.
 * @param {Array} array - An array to sort.
 * @param {comparefn} compare - A comparison function.
 * When called with any two values `a` and `b` of an array,
 * if it returns a positive number, then `b` precedes `a` in the sorted array.
 * Otherwise `a` precedes `b`.
 */
export function selectionSort(array, compare) {
  let min;
  const n = array.length;
  for (let i = 0; i < n - 1; i++) {
    min = i;
    for (let j = i + 1; j < n; j++) {
      if (compare(array[j], array[min]) < 0) min = j;
    }
    // Swap
    [array[i], array[min]] = [array[min], array[i]];
  }
}

/**
 * @callback comparefn
 * @param a
 * @param b
 * @returns {number}
 */
