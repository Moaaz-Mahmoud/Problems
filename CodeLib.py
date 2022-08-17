import datetime as dt
import math as m
def read_int():
  return int(input())
def read():
  return list(map(int, input().split(' ')))

def argsort(seq):
    return sorted(range(len(seq)), key=seq.__getitem__)


def solve():
  n, m = read()
  s = ''
  for i in range(n):
    s = s + ''.join(input().split(' '))
    
  if 'p' in s and 'i' in s and 'e' in s:
    print('Cutie Pie!')
  else:
    print('Sorry Man')
  

    


  

  
  

  

################################################

_t = 1
_t = int(input())
for _i in range(_t-1):
  solve()
  input() # !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
solve()