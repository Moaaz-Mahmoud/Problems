
n = int(input())
A = [0]*n
strA = input().split(' ')
for i in range (0, n):
    A[i] = int(strA[i])
for i in range (1, n):
    A[i] += A[i-1]
ans = 0
for i in range (0, n-1):
    if A[n-1] - A[i] == A[i]:
        ans += 1
print(ans)