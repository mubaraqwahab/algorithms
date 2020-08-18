// import { min, max } from "./minmax.js"

/**
 * Return the median value of `a`, `b` and `c`.
 * @param {T} a
 * @param {T} b
 * @param {T} c
 * @param {function(T, T): number} compare A comparison function.
 * When called with `a` and `b`, if it returns a positive number, then `a` is considered larger than `b`
 * Otherwise `a` is considered smaller than `b`.
 */
export function medianOfThree(a, b, c, compare) {
  if (compare(a, b) < 0) {
    if (compare(b, c) < 0) return b;
    else if (compare(a, c) < 0) return c;
    else return a;
  } else {
    if (compare(a, c) < 0) return a;
    else if (compare(b, c) < 0) return c;
    else return b;
  }

  // OR
  // return min(max(a, b, compare), max(min(a, b, compare), c, compare), compare);

  // See https://stackoverflow.com/q/1582356/12695621
}
