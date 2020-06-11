from sqrtfloor import sqrt_floor

def sieve(n):
  """Implement the sieve of Eratosthenes.

  Param: a positive integer n > 1.
  Output: a list of all prime numbers not greater than n.
  """

  candidates = [ p for p in range(2, n+1) ]

  for p in range(2, sqrt_floor(n)):
    if candidates[p-2] != None:
      for j in range(p*p, n+1, p):
        candidates[j-2] = None

  return [ q for q in candidates if q != None ]


# Test drive
if __name__ == '__main__':
    print(sieve(100))
