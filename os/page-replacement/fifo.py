def FIFO(references: list, page_frames: list):
    """Perform page replacement using the first-in first-out algorithm.

    Inputs:
    * references - a list (queue) of page references
    * page_frames - a list representing the page frames.

    Output: the number of page faults.
    """

    # Create a copy of the original to avoid modifying it
    page_frames = page_frames[:]
    N = len(page_frames)

    page_faults = 0
    next_in_index = -1

    for reference in references:

        if reference not in page_frames:
            page_faults += 1

            # Get the index of the frame for the next page to be brought in.
            next_in_index = (next_in_index + 1) % N

            # Place the current page in there.
            page_frames[next_in_index] = reference

            print_page_frames(reference, page_frames)
        else:
            print_page_frames(reference)

    return page_faults

def print_page_frames(reference, page_frames=[]):
    print(f"Reference: {reference}, Page frames: {page_frames if page_frames else ''}")