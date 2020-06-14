import { min, max, medianOfThree } from "./utils.js";

// TEST

const objs = [
  { x: 10, y: 120 },
  { x: 15, y: 17 },
  { x: 20, y: 31 },
];

// Compare by y property
const key = (obj) => obj.y;

const smallest = min(min(objs[0], objs[1], key), objs[2], key);
const largest = max(max(objs[0], objs[1], key), objs[2], key);
const median = medianOfThree(...objs, key);

console.log("Given", objs, "and comparing by y property");
console.log("min is", smallest);
console.log("max is", largest);
console.log("median is", median);
