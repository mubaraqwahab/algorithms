import { selectionSort } from "./selectionsort.js";
import { bubbleSort } from "./bubblesort.js";
import { mergesort } from "./mergesort.js";

let arr = [89, 68, 45, 90, 29, 34, 17];

console.log(`Before: ${arr}`);

// selectionSort(arr);
// bubbleSort(arr);
mergesort(arr);

console.log(`After: ${arr}`);

// TIMING

// let arr = [];
// for (let i = 0; i < 50; i++) {
//   arr.push(Math.floor(Math.random() * 100))
// }

// let arr2 = [ ...arr ];
// let arr3 = [ ...arr ];

// console.log(`\nBefore: ${arr}\n`);

// console.time("Selection sort")
// selectionSort(arr);
// console.timeEnd("Selection sort")

// console.time("bubblesort")
// bubbleSort(arr2);
// console.timeEnd("bubblesort")

// console.time("mergesort")
// mergesort(arr3)
// console.timeEnd("mergesort")

// console.log(`\nAfter: ${arr}`);
