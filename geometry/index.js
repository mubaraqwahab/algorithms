import { bruteForceClosestPair } from "./closestpair.js";

const points = [
  { x: 1, y: 2 },
  { x: 2, y: 3 },
  { x: 3, y: 10 },
  { x: 4, y: 10 },
];

const [i, j] = bruteForceClosestPair(points);

console.log(
  `The closest points in`,
  points,
  `are`,
  points[i],
  `and`,
  points[j]
);
