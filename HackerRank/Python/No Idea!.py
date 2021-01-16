from collections import Counter

line = input().split(' ')
n, m = int(line[0]), int(line[1])

A, S, T = [], [], []
line = input().split()
for l in line:
    A.append(int(l))
line = input().split()
for l in line:
    S.append(int(l))
line = input().split()
for l in line:
    T.append(int(l))
    
score = 0
A = Counter(A)
for s in S:
    score += A[s]
for t in T:
    score -= A[t]
print(score)
