/**
 * Sort an array by bubble sort.
 * @param {array} array - An array to sort.
 * @param {function(T,T): number} compare - A comparison function.
 * When called with any two values `a` and `b` of an array,
 * if it returns a positive number, then `b` precedes `a` in the sorted array.
 * Otherwise `a` precedes `b`.
 */
export function bubbleSort(array, compare) {
  let swaps;
  const n = array.length;
  for (let i = 0; i < n - 1; i++) {
    swaps = 0;
    for (let j = 0; j < n - 1; j++) {
      if (compare(array[j], array[j + 1]) > 0) {
        [array[j], array[j + 1]] = [array[j + 1], array[j]];
        swaps++;
      }
    }
    if (swaps === 0) break;
  }
}
