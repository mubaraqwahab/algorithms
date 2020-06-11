import { min } from "../utils.js";

/**
 * Find the distance between the closest pair of Cartesian points (x,y) in `points` by brute force.
 * @param {Array<{ x, y }>} points
 */
export function bruteForceClosestPair(points) {
  let d = Number.POSITIVE_INFINITY,
    norm;
  const n = points.length;
  for (let i = 0; i < n - 1; i++) {
    for (let j = i + 1; j < n; j++) {
      norm =
        Math.pow(points[i].x - points[j].x, 2) +
        Math.pow(points[i].y - points[j].y, 2);
      d = min(d, norm);
    }
  }
  return Math.sqrt(d);
}
