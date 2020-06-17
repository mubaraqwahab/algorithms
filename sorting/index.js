import { selectionSort } from "./selectionsort.js";
import { bubbleSort } from "./bubblesort.js";
import { mergesort } from "./mergesort.js";
import { quicksort } from "./quicksort.js";

// TEST

let arr = [89, 68, 45, 90, 29, 34, 17];

const compareNum = (a, b) => a - b;

console.log(`Before: ${arr}`);

selectionSort(arr, compareNum);
bubbleSort(arr, compareNum);
mergesort(arr, compareNum);
quicksort(arr, compareNum);

console.log(`After: ${arr}`);

/**/

/*/ STABILITY TEST

const arr = [
  { value: 23, pos: 1 },
  { value: 23, pos: 2 },
  { value: 89, pos: 1 },
  { value: 23, pos: 3 },
  { value: 89, pos: 2 },
  { value: 17, pos: 1 },
  { value: 34, pos: 1 },
];

const compareValues = (a, b) => a.value - b.value;

// selectionSort(arr, compareValues);
// bubbleSort(arr, compareValues);
// mergesort(arr, compareValues);
quicksort(arr, compareValues);

console.log(arr);

/**/

/*/ TIME TEST

let arr = [];
for (let i = 0; i < 100000; i++) {
  arr.push(Math.floor(Math.random() * 1000));
}

let arr2 = [...arr];
let arr3 = [...arr];
let arr4 = [...arr];

const compareNum = (a, b) => a - b;

console.log("\nSTART TEST\n");

console.time("Selection sort");
selectionSort(arr, compareNum);
console.timeEnd("Selection sort");

console.time("bubblesort");
bubbleSort(arr2, compareNum);
console.timeEnd("bubblesort");

console.time("mergesort");
mergesort(arr3, compareNum);
console.timeEnd("mergesort");

console.time("quicksort");
quicksort(arr4, compareNum);
console.timeEnd("quicksort");

/**/
