/**
 * Find the distance between the closest pair of Cartesian points (x,y) in `points` by brute force.
 * @param {Array<{ x, y }>} points - An array of n (n >= 2) points
 */
export function bruteForceClosestPair(points) {
  let d = Number.POSITIVE_INFINITY;
  let norm, pair;
  const n = points.length;

  for (let i = 0; i < n - 1; i++) {
    for (let j = i + 1; j < n; j++) {
      norm = Math.pow(points[i].x - points[j].x, 2) + Math.pow(points[i].y - points[j].y, 2);

      if (norm < d) {
        d = norm;
        pair = [i, j];
      }
    }
  }
  return pair;
}
