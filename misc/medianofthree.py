def median_of_three(a, b, c, key=None):
  """Return the median of three elements a, b and c.

  Params:
  - three elements a, b, and c
  - key, a one-argument ordering function. (See https://docs.python.org/3/library/stdtypes.html#list.sort)

  Output: the median of a, b and c.
  """

  if key: return max(min(a, b, key=key), c, key=key)
  return max(min(a, b), c)

if __name__ == '__main__':
  # a = 3; b = 9; c = 0
  a = (1,2); b = (2,3); c = (4,1);
  # Find the median using the second coordinates
  median = median_of_three(a, b, c, lambda n: n[1])
  print(f"Median of {a}, {b} and {c} is {median}")