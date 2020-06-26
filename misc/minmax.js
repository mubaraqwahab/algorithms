/**
 * Return the smaller value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(*): *} [key] `key` should return the key by which `a` and `b` are compared.
 * Ignore this if you want to compare by actual values. (See https://docs.python.org/3/library/stdtypes.html#list.sort)
 */
export function min(a, b, key = (n) => n) {
  if (key(a) <= key(b)) return a;
  else return b;
}

/**
 * Return the larger value of `a` and `b`.
 * @param {any} a
 * @param {any} b
 * @param {function(*): *} [key] - `key` should return the key by which `a` and `b` are compared.
 * Ignore this if you want to compare by actual values.
 */
export function max(a, b, key = (n) => n) {
  if (key(a) >= key(b)) return a;
  else return b;
}
