import { selectionSort } from "./selectionsort.js";
import { bubbleSort } from "./bubblesort.js";
import { mergesort } from "./mergesort.js";

let arr = [89, 68, 45, 90, 29, 34, 17];

const compareNum = (a, b) => a - b;

console.log(`Before: ${arr}`);

// selectionSort(arr, compareNum);
// bubbleSort(arr, compareNum);
mergesort(arr, compareNum);

console.log(`After: ${arr}`);

// TIMING

// let arr = [];
// for (let i = 0; i < 100000; i++) {
//   arr.push(Math.floor(Math.random() * 1000))
// }

// let arr2 = [ ...arr ];
// let arr3 = [ ...arr ];

// // console.log(`\nBefore: ${arr}\n`);
// console.log("Start\n");
// console.time("Selection sort")
// selectionSort(arr, compareNum);
// console.timeEnd("Selection sort")

// console.time("bubblesort")
// bubbleSort(arr2, compareNum);
// console.timeEnd("bubblesort")

// console.time("mergesort")
// mergesort(arr3, compareNum);
// console.timeEnd("mergesort")

// // console.log(`\nAfter: ${arr}`);
