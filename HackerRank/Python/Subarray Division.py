import math
import os
import random
import re
import sys

# Complete the birthday function below.
def birthday(s, d, m):  #Array, required sum, required length
    n = len(s)
    if m > n:
        return 0
    i, j = 0, 0
    sum_ = sum(s[:m])
    ans_ = 0
    j = m-1
    while True:
        if sum_ == d:
            ans_ += 1
        sum_ -= s[i]
        i += 1; j += 1
        if j == n:
            break
        sum_ += s[j]
    
    return ans_

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = list(map(int, input().rstrip().split()))

    dm = input().rstrip().split()

    d = int(dm[0])

    m = int(dm[1])

    result = birthday(s, d, m)

    fptr.write(str(result) + '\n')

    fptr.close()
