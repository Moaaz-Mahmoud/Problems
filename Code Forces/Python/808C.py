
from operator import itemgetter 
import math

line1 = input(); line1 = line1.split(' ')
n, w = int(line1[0]), int(line1[1])
line2 = input(); line2 = line2.split(' ')
A = []
for i in range(0, n):
    A.append(   [ int(line2[i]),  0,  False, i+1 ]   )

#Pass 1: Fill them all to their halves or pour until the pot is empty.
A.sort(reverse = True, key = itemgetter(0))
left1_2 = n
while w:
    if (not w) or (not left1_2): break
    for i in range(0, n):
        if (not w) or (not left1_2): break
        if(A[i][2] == False):
            A[i][1] += 1
            w -= 1
            if(A[i][1] >= math.ceil(A[i][0]/2)):
                left1_2 -= 1
                A[i][2] = True 

#Pass 2: Fill them all or pour until the pot is empty.
vacant = 0
for i in range(0, n):
    vacant += A[i][0] - A[i][1]
while(1):
    if (not vacant) or (not w): break
    for i in range (0, n):
        if(A[i][1] < A[i][0]):
            if (not vacant) or (not w): break
            w -= 1
            vacant  -= 1
            A[i][1] += 1

#Return them to their original order.
A.sort(key = itemgetter(3))
flag = True
if(w):
    print(-1)
    flag = False
else:
    for i in range(0, n):
        if(A[i][1] < math.ceil(A[i][0]/2)):
            print(-1)
            flag = False
            break
if(flag):
    for i in A:
        print(i[1], end = ' ')

