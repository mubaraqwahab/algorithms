def SCAN(requests: list, head: int):
    """Service disk requests using the scan (elevator) algorithm.

    Inputs:
    * requests - a list (queue) of requests
    * head - a current read/write head position

    Output: a tuple of the total number of head movements and the head traversal path.
    """

    head_movements = 0
    head_traversal = [ head ]

    def move_head(req):
        """Moves the head to the given request.

        Updates the head_movements and head_traversal as necessary.
        """

        nonlocal head_traversal, head_movements, head

        head_traversal.append(req)
        head_movements += abs(req - head)
        head = req

    requests = requests[:]
    requests.sort()

    print()
    print(requests)
    print()

    # Find the index of the next request to the head (towards the left)
    first = largest_int_smaller_than(requests, head)

    # Start servicing until you reach the leftmost request
    for i in range(first, -1, -1):
        move_head(requests[i])

    # Go all the way to left end
    move_head(0)

    # Service in the opposite direction
    for i in range(first + 1, len(requests)):
        move_head(requests[i])

    return head_movements, head_traversal

def largest_int_smaller_than(integers: list, limit: int):
    """Return the index of the largest integer in a sorted list greater than a limit."""

    result = -1
    for i in range(len(integers)):
        if integers[i] < limit:
            result = i
        elif integers[i] == limit:
            result = i
            break
        else:
            break
    return result
