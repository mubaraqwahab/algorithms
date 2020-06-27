/**
 * Return the smaller value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(any, any): number} compare A comparison function.
 * When called with `a` and `b`, if it returns a positive number,
 * then `a` is considered larger than `b`.
 * Otherwise `a` is considered smaller than `b`.
 */
export function min(a, b, compare) {
  if (compare(a, b) <= 0) return a;
  else return b;
}

/**
 * Return the index of the leftmost smallest element in a non-empty array.
 * @param {Array<T>} array
 * @param {function(any, any): number} compare A comparison function. Same as for `min`.
 */
export function minElement(array, compare) {
  let min = 0;
  for (let i = 1; i < array.length; i++) {
    if (compare(array[i], array[min]) < 0)
      min = i;
  }
  return min;
}

/**
 * Return the larger value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(any, any): number} compare A comparison function. Same as for `min` function.
 */
export function max(a, b, compare) {
  if (compare(a, b) > 0) return a;
  else return b;
}

/**
 * Return the index of the leftmost largest element in a non-empty array.
 * @param {Array<T>} array
 * @param {function(any, any): number} compare A comparison function. Same as for `min`.
 */
export function maxElement(array, compare) {
  let max = 0;
  for (let i = 1; i < array.length; i++) {
    if (compare(array[i], array[max]) > 0)
      max = i;
  }
  return max;
}