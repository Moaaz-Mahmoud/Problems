n = int(input())
A = input().split(' ')
A = set(map(int, A))
m = int(input())
B = input().split(' ')
B = set(map(int, B))

C = set()
C = A.difference(B).union(B.difference(A))
C = list(C)
C.sort()
for c in C:
    print(c)
