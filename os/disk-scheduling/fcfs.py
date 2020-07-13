def FCFS(requests: list, head: int):
    """Service disk requests using the first-come first-served algorithm.

    Inputs:
    * requests - a list (queue) of requests
    * head - a current read/write head position

    Output: a tuple of the total number of head movements and the head traversal path.
    """

    head_movements = 0
    head_traversal = [ head ]

    for request in requests:
        head_traversal.append(request)
        head_movements += abs(request - head)
        head = request

    return head_movements, head_traversal
