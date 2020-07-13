def LRU(reference_string: str, page_frames: list):
    """Perform page replacement using the least-recently-used algorithm.

    Inputs:
    * references - a list (queue) of page references
    * page_frames - a list representing the page frames.

    Output: the number of page faults.
    """

    page_frames = page_frames[:]

    page_faults = 0
    lru_index = -1
    time_stamps = [-1] * len(page_frames)

    for i in range(len(reference_string)):
        reference = reference_string[i]
        if reference not in page_frames:
            page_faults += 1

            # Find the index of the LRU page in time_stamps (and thus page_frames)
            lru_index = time_stamps.index(min(time_stamps))

            # Put the new page in that index
            page_frames[lru_index] = reference

            # Update the time for that index
            time_stamps[lru_index] = i

            print_page_frames(reference, page_frames)
        else:
            # Update the time for the page
            time_stamps[page_frames.index(reference)] = i
            print_page_frames(reference)

    return page_faults

def print_page_frames(reference, page_frames=[]):
    print(f"Reference: {reference}, Page frames: {page_frames if page_frames else ''}")