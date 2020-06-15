import { sequentialSearch } from "./sequentialsearch.js";
import { binarySearch } from "./binarysearch.js";
import { bruteForceStringMatch } from "./stringmatching.js";
import { mergesort as sort } from "../sorting/mergesort.js";

// const arr = [89, 45, 68, 90, 29, 34, 17];

const arr = [
  { gender: "male", age: 89 },
  { gender: "female", age: 45 },
  { gender: "male", age: 68 },
  { gender: "female", age: 90 },
  { gender: "male", age: 29 },
  { gender: "female", age: 34 },
  { gender: "male", age: 17 },
];

// Choose age of random element from array
const key = arr[Math.floor(Math.random() * arr.length)].age;

// Sort the array by age
sort(arr, (a, b) => a.age - b.age);
console.log(arr);

let position;
// Find by age
const compareKey = (elem) => elem.age;

// Test sequential search
position = sequentialSearch(arr, key, compareKey);
console.log("\nSequential search:");
printResult(`Element with age ${key}`, position, "arr");

// Test binary search
position = binarySearch(arr, key, compareKey);
console.log("\nBinary search:");
printResult(`Element with age ${key}`, position, "arr");

// Test string matching
const text = "Nobody noticed him.";
const pattern = "not";
const index = bruteForceStringMatch(text, pattern);
console.log("\nString matching");
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
