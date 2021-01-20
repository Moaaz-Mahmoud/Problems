from collections import defaultdict

line = input().split(' ')
n, m = int(line[0]), int(line[1])

A, B = defaultdict(list), defaultdict(list)
for i in range(n):
    word = input()
    A[word].append(i+1)
for i in range(m):
    word = input()
    if A[word] == []:
        print(-1)
    else:
        for i in A[word]:
            print(i, end = ' ')
        print()

