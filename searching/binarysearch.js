/**
 * Find the (not necessarily first) position of an element in a sorted array
 * that matches `searchKey` using binary search.
 * Return -1 if no such element is found.
 *
 * @param {array} array - a sorted array to search.
 * @param {*} searchKey - the item to search for.
 * @param {function(T): T} compareKey - a function. It is called on elements of the array
 * (and on `searchKey`) once and should return the key by which the element is compared.
 * Ignore this if you just want to compare by actual values.
 */
export function binarySearch(array, searchKey, compareKey = (e) => e) {
  let left = 0;
  let right = array.length - 1;
  let mid, midElemKey;
  const search = compareKey(searchKey);

  while (left <= right) {
    mid = Math.floor((left + right) / 2);
    midElemKey = compareKey(array[mid]);

    if (midElemKey === search) return mid;
    else if (midElemKey > search) right = mid - 1;
    else left = mid + 1;
  }
  return -1;
}
