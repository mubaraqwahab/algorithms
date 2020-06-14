/**
 * Return the smaller value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(*): *} [key] a one-argument ordering function
 */
export function min(a, b, key = (n) => n) {
  if (key(a) <= key(b)) return a;
  else return b;
}

/**
 * Return the larger value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(*): *} [key] a one-argument ordering function
 */
export function max(a, b, key = (n) => n) {
  if (key(a) >= key(b)) return a;
  else return b;
}

/**
 * Return the median value of `a`, `b` and `c`.
 * @param {any} a
 * @param {any} b
 * @param {any} c
 * @param {function(*): *} [key] a one-argument ordering function. (See https://docs.python.org/3/library/stdtypes.html#list.sort)
 */
export function medianOfThree(a, b, c, key = (n) => n) {
  const p = key(a),
    q = key(b),
    r = key(c);
  if (p < q) {
    if (q < r) return b;
    else if (p < r) return c;
    else return a;
  } else {
    if (p < r) return a;
    else if (q < r) return c;
    else return b;
  }
  // OR
  // return min(max(a, b, key), max(min(a, b, key), c, key), key);

  // See https://stackoverflow.com/q/1582356/12695621
}
