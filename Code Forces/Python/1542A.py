import math
from sys import stdout

for j in range(int(input())):
    n = int(input())
    odd, even = 0, 0
    ln = input().split(' ')
    for a in ln:
        odd += int(a) & 1
        even += 1 - int(a) & 1
    if odd == even: print("Yes")
    else:           print("No")
