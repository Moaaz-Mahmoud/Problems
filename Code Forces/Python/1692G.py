def read_arr():
  return list(map(int, input().split(' ')))

_t = 1
_t = int(input())

for _i in range(_t):
  n, k = read_arr()
  A = read_arr()
  B = [0]*n
  ans, cur = 0, 0
  for i in range(1, n):
    if A[i]*2 > A[i-1]:
      B[i] = 1
  for b in B:
    if b == 1:
      cur += 1
      if cur >= k: ans += 1
    else:
      cur = 0
      

  print(ans)
