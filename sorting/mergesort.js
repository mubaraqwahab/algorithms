/**
 * Sort an array by mergesort.
 * @param {array} array - An array to sort.
 * @param {function(T,T): number} compare - A comparison function.
 * When called with any two values `a` and `b` of an array,
 * if it returns a positive number, then `b` precedes `a` in the sorted array.
 * Otherwise `a` precedes `b`.
 */
export function mergesort(array, compare) {
  const n = array.length;

  if (n > 1) {
    const half1 = array.slice(0, Math.floor(n / 2));
    const half2 = array.slice(Math.floor(n / 2));

    mergesort(half1, compare);
    mergesort(half2, compare);

    merge(half1, half2, array, compare);
  }
}

/**
 * Merge two sorted arrays into a third sorted array.
 * @param {array} arrIn1 - a sorted array
 * @param {array} arrIn2 - another sorted array
 * @param {array} arrOut - an array to merge arrIn1 and arrIn2 into.
 * @param {function(T,T): number} compare - A comparison function.
 */
function merge(arrIn1, arrIn2, arrOut, compare) {
  let i = 0,
    j = 0,
    k = 0;
  const p = arrIn1.length,
    q = arrIn2.length;

  while (i < p && j < q) {
    if (compare(arrIn1[i], arrIn2[j]) <= 0) {
      arrOut[k] = arrIn1[i];
      i++;
    } else {
      arrOut[k] = arrIn2[j];
      j++;
    }
    k++;
  }

  if (i < p) {
    for (let m = i; m < p; m++, k++) {
      arrOut[k] = arrIn1[m];
    }
  } else {
    for (let m = j; m < q; m++, k++) {
      arrOut[k] = arrIn2[m];
    }
  }
}
