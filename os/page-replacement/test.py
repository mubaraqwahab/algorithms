import random
from fifo import FIFO
from lru import LRU

references = [ random.randrange(10) for i in range(20) ]
# references = '7012030423030321201701'

page_frames = [ None, None, None, None ]

print(f"References: {references}")
print(f"Page frames: {page_frames}")


print("\nFIFO\n====")
FIFO_faults = FIFO(references, page_frames)
print("\nPage faults =", FIFO_faults)

print("\nLRU\n===")
LRU_faults = LRU(references, page_frames)
print("\nPage faults =", LRU_faults)