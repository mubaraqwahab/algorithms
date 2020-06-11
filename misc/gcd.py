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

def gcd_bruteforce(m, n):
  """Compute the greatest common divisor (GCD) of m and n by brute force.

  Params: Two positive integers m and n.
  Output: The GCD of m and n
  """

  t = min(m, n)
  while m % t != 0 or n % t != 0:
    t -= 1
  return t


# Test drive
if __name__ == '__main__':
  print("Compute GCD")
  a = int(input("First number? "))
  b = int(input("Second number? "))
  print(f"GCD of {a} and {b} = {gcd_euclid(a, b)}")
  print(f"GCD of {a} and {b} = {gcd_bruteforce(a, b)}")
