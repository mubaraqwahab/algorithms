/**
 * Find the position of key in array using sequential search. Return -1 if key is not in array
 * @param {Array<any>} array
 * @param {any} key
 */
export function sequentialSearch(array, key) {
  for (let i = 0; i < array.length; i++) {
    if (array[i] === key) {
      return i;
    }
  }
  return -1;
}
