def common_elements(p, q):
  """Return a list of all elements common to sorted lists p and q."""

  i = j = 0
  elems = []

  while i < len(p) and j < len(q):
    if p[i] < q[j]: i += 1
    elif p[i] > q[j]: j += 1
    else:
      elems.append(q[j])
      j += 1
      i += 1

  return elems


# Test drive
if __name__ == '__main__':
  from random import randrange

  # Test function
  def test(p, q):
    result = p[:]
    q = q[:]
    for e in p:
      if e in q: q.remove(e)
      else: result.remove(e)
    return result

  health = True
  for j in range(10):
    p = [ randrange(20) for i in range(randrange(50)) ]
    q = [ randrange(50) for i in range(randrange(50)) ]
    p.sort()
    q.sort()

    if common_elements(p, q) != test(p, q):
      health = False
      break

  if health:
    print("Alhamdulillah, it works!")
  else:
    print("Something's wrong")