/**
 * Sort an array by selection sort.
 * @param {Array<number|string>} array
 */
export function bubbleSort(array) {
  let swaps;
  const n = array.length;
  for (let i = 0; i < n - 1; i++) {
    swaps = 0;
    for (let j = 0; j < n - 1; j++) {
      if (array[j] > array[j + 1]) {
        [array[j], array[j + 1]] = [array[j + 1], array[j]];
        swaps++;
      }
    }
    if (swaps === 0) break;
  }
}
