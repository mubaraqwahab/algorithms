def SSTF(requests: list, head: int):
    """Service disk requests using the shortest-seek-time-first algorithm.

    Inputs:
    * requests - a list (queue) of requests
    * head - a current read/write head position

    Output: a tuple of the total number of head movements and the head traversal path.
    """

    head_movements = 0
    head_traversal = [ head ]

    # Use this to indicate which requests have been serviced
    flags = [ False ] * len(requests)

    while not all(flags):
        # Get the distances of all requests from the current head
        request_distances = [ abs(request - head) for request in requests ]

        # Pick each request
        for i in range(len(requests)):
            # Check if it's not been serviced and it has the SST
            if not flags[i]:
                sst = min([ request_distances[j]
                            for j in range(len(request_distances))
                            if not flags[j] ])
                if request_distances[i] == sst:
                    flags[i] = True
                    head_traversal.append(requests[i])
                    head_movements += request_distances[i]
                    head = requests[i]

    return head_movements, head_traversal
