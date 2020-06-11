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
    # Little optimization first :)
    if len(p) < len(q):
      shorter = p
      longer = q
    else:
      shorter = q
      longer = p
    # Then ...
    result = [ e for e in shorter ]
    for e in shorter:
      if e in longer: longer.remove(e)
      else: result.remove(e)

    return result

  health = True
  for j in range(10):
    p = [ randrange(20) for i in range(randrange(50)) ]
    q = [ randrange(50) for i in range(randrange(50)) ]
    p.sort()
    q.sort()

    health = health and common_elements(p, q) == test(p, q)

  if health:
    print("Alhamdulillah, it works!")
  else:
    print("Something's wrong")