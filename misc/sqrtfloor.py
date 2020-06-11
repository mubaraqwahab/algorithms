def sqrt_floor(n):
  """Return the floor of the square root of a positive integer n."""

  candidate = 1
  for p in range(2, n+1):
    if p*p > n: break
    candidate = p
  return candidate


# Test drive
if __name__ == '__main__':
  from math import sqrt, floor

  # Test function
  def test(n):
    return floor(sqrt(n))

  for i in range(1, 10001):
    health = sqrt_floor(i) == test(i)

  if health:
    print("Alhamdulillah, all's well")
  else:
    print("Something's wrong")