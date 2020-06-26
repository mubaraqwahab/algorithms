/**
 * Return the smaller value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(*): *} compare A comparison function.
 * When called with `a` and `b`, if it returns a positive number, then `a` is considered larger than `b`
 * Otherwise `a` is considered smaller than `b`.
 */
export function min(a, b, compare) {
  if (compare(a, b) <= 0) return a;
  else return b;
}

/**
 * Return the larger value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(*): *} compare A comparison function. Same as for `min` function.
 */
export function max(a, b, compare) {
  if (compare(a, b) > 0) return a;
  else return b;
}
