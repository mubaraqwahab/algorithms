import { selectionSort } from "./selectionsort.js";
import { bubbleSort } from "./bubblesort.js";
import { mergesort } from "./mergesort.js";

const arr = [89, 45, 68, 90, 29, 34, 17];
console.log(`Before: ${arr}`);

// selectionSort(arr);
bubbleSort(arr);
// mergesort(arr)

console.log(`After: ${arr}`);
