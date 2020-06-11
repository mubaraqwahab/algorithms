/**
 * Find the first occurrence of pattern in text using brute force. Return -1 if pattern is not in text.
 * @param {string} text
 * @param {string} pattern
 */
export function bruteForceStringMatch(text, pattern) {
  const n = text.length,
    m = pattern.length;
  for (let i = 0; i < n - m + 1; i++) {
    for (let j = 0; j < m; j++) {
      if (text[i + j] !== pattern[j]) break;
      else if (j === m - 1) return i;
    }
  }
  return -1;
}
