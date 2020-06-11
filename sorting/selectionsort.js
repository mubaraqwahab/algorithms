/**
 * Sort an array by selection sort.
 * @param {Array<number|string>} array
 */
export function selectionSort(array) {
  let min;
  const n = array.length;
  for (let i = 0; i < n - 1; i++) {
    min = i;
    for (let j = i + 1; j < n; j++) {
      if (array[j] < array[min]) min = j;
    }
    // Swap
    [array[i], array[min]] = [array[min], array[i]];
  }
}
