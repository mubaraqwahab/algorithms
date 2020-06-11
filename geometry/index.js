import { bruteForceClosestPair } from "./closestpair.js";

const points = [
  { x: 1, y: 2},
  { x: 2, y: 2},
  { x: 3, y: 10},
];

const distance = bruteForceClosestPair(points)

console.log(`The closest points in`, points, `are ${distance} unit(s) apart.`);