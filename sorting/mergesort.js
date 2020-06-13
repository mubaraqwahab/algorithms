/**
 * Sort an array by mergesort.
 * @param {Array<number|string>} array
 */
export function mergesort(array) {
  const n = array.length;
  const fl = Math.floor,
    ce = Math.ceil;

  if (array.length > 1) {
    const half1 = array.slice(0, fl(n / 2));
    const half2 = array.slice(fl(n / 2));

    mergesort(half1);
    mergesort(half2);

    merge(half1, half2, array);
  }
}

/**
 * Merge two sorted arrays into a third sorted array
 * @param {Array<number|string>} arrIn1 - a sorted array
 * @param {Array<number|string>} arrIn2 - another sorted array
 * @param {Array<number|string>} arrOut - an array to merge arrIn1 and arrIn2 into.
 */
function merge(arrIn1, arrIn2, arrOut) {
  let i = 0,
    j = 0,
    k = 0;
  const p = arrIn1.length,
    q = arrIn2.length;

  while (i < p && j < q) {
    if (arrIn1[i] <= arrIn2[j]) {
      arrOut[k] = arrIn1[i];
      i++;
    } else {
      arrOut[k] = arrIn2[j];
      j++;
    }
    k++;
  }

  if (i < p) {
    for (let m = i; m < p; m++) {
      arrOut[k] = arrIn1[m];
      k++;
    }
  } else {
    for (let m = i; m < q; m++) {
      arrOut[k] = arrIn2[m];
      k++;
    }
  }
}
