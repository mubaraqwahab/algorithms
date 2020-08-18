/**
 * Sort an array by selection sort.
 * @param {Array<T>} array - An array to sort.
 * @param {function(T,T): number} compare - A comparison function.
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
