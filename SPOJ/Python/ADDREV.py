t = int(input())
 
for t_ in range(0, t):
    n = input().split(' ')
    n, m = n[0][::-1], n[1][::-1]
 
    n = int(n)
    m = int(m)
    sum = n + m
    sum = str(sum)
    sum = sum[::-1]
    sum = int(sum)
 
    print(sum)
