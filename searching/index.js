import { sequentialSearch } from "./sequentialsearch.js";
import { bruteForceStringMatch } from "./stringmatching.js"

// Test sequential search
const arr = [89, 45, 68, 90, 29, 34, 17];
const key = 90;

const position = sequentialSearch(arr, key);
if (position !== -1) {
  console.log(`${key} is in ${arr} at position ${position}.`);
} else {
  console.log(`${key} is not in ${arr}.`);
}

// Test string matching
const text = "Nobody noticed him."
const pattern = "not";
const index = bruteForceStringMatch(text, pattern);
if (index !== -1) {
  console.log(`"${pattern}" is in "${text}" at positiong ${index}.`)
} else {
  console.log(`"${pattern}" is not in "${text}".`);
}