import { sequentialSearch } from "./sequentialsearch.js";
import { binarySearch } from "./binarysearch.js";
import { bruteForceStringMatch } from "./stringmatching.js";
import { mergesort as sort } from "../sorting/mergesort.js";

const arr = [89, 45, 68, 90, 29, 34, 17];
// Choose random number from array
const key = arr[Math.floor(Math.random() * arr.length)];

// Sort the array
sort(arr, (a, b) => a - b);
console.log(arr);

let position;

// Test sequential search
position = sequentialSearch(arr, key);
console.log("Sequential search:");
printResult(key, position, arr);

// Test binary search
position = binarySearch(arr, key);
console.log("Binary search:");
printResult(key, position, arr);

// Test string matching
const text = "Nobody noticed him.";
const pattern = "not";
const index = bruteForceStringMatch(text, pattern);
printResult(pattern, index, text);

function printResult(key, position, source) {
  key = JSON.stringify(key);
  source = JSON.stringify(source);

  if (position !== -1) {
    console.log(`${key} is in ${source} at position ${position}.`);
  } else {
    console.log(`${key} is not in ${source}.`);
  }
}
