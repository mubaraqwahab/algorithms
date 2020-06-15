/**
 * Find the position of the first element in `array`
 * that matches `searchKey` using sequential search.
 * Return -1 if no such element is found.
 *
 * @param {array} array - an array to search.
 * @param {*} searchKey - the item to search for.
 * @param {function(T): T} compareKey - `compareKey` is called on elements of the array
 * at most once and should return the key by which the element is compared with `searchKey`.
 * Ignore this if you just want to compare by actual values.
 */
export function sequentialSearch(array, searchKey, compareKey = (e) => e) {
  for (let i = 0; i < array.length; i++) {
    if (compareKey(array[i]) === searchKey) {
      return i;
    }
  }
  return -1;
}
