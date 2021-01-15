#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    s = input()
    F = {}
    for i in range(ord('a'), ord('z')+1):
        F[chr(i)] = 0
    for c in s:
        F[c] += 1
    m1, m2, m3 = ('a', -1), ('a', -1), ('a', -1)
    for c in F.keys():
        f = F[c]
        if(f > m1[1]):
            m1 = (c, f)
    for c in F.keys():
        if c == m1[0]:
            continue
        f = F[c]
        if(f > m2[1]):
            m2 = (c, f)
    for c in F.keys():
        if c == m1[0] or c == m2[0]:
            continue
        f = F[c]
        if(f > m3[1]):
            m3 = (c, f)
    print(
        m1[0], ' ', m1[1], '\n',
        m2[0], ' ', m2[1], '\n',
        m3[0], ' ', m3[1], '\n',
        sep = '', end = ''
    )
