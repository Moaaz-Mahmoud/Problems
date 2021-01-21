import math
import os
import random
import re
import sys

#
# Complete the 'rotateLeft' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER d
#  2. INTEGER_ARRAY arr
#

def rotateLeft(d, arr):
    n = len(arr)
    A = [0]*n
    for i in range(0, n):
        A[(i-d+n)%n] = arr[i]
    return A
