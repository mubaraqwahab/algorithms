def gcd_euclid(m, n):
  """Compute the greatest common divisor (GCD) of m and n by Euclid's algorithm.

  Params: Two nonnegative not-both-zero integers m and n.
  Output: The GCD of m and n
  """
  while n:
    r = m % n
    m = n
    n = r
  return m

# Test drive
if __name__ == '__main__':
  print("Compute GCD")
  a = int(input("First number? "))
  b = int(input("Second number? "))
  print(f"GCD of {a} and {b} = {gcd_euclid(a, b)}")
