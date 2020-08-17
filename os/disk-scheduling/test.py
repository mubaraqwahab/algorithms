import random
from fcfs import FCFS
from sstf import SSTF
from scan import SCAN

requests = [ random.randrange(500) for i in range(20) ]
print(f"Requests: {requests}")
head = int(input("What's the current position of the disk head? "))

fcfs_head_movements, fcfs_head_traversal = FCFS(requests, head)
print("FCFS\n====")
print(f"Total head movements: {fcfs_head_movements}")
print(f"Head traversal: {fcfs_head_traversal}")

sstf_head_movements, sstf_head_traversal = SSTF(requests, head)
print("\nSSTF\n====")
print(f"Total head movements: {sstf_head_movements}")
print(f"Head traversal: {sstf_head_traversal}")

scan_head_movements, scan_head_traversal = SCAN(requests, head)
print("\nSCAN\n====")
print(f"Total head movements: {scan_head_movements}")
print(f"Head traversal: {scan_head_traversal}")