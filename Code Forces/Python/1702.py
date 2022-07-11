import math
def read_int():
  return int(input())
def read():
  return list(map(int, input().split(' ')))



def solve():
  n = read_int()
  print(n-10**int(math.log10(n)))
  

################################################

_t = 1
_t = int(input())
for _i in range(_t):
  solve()
