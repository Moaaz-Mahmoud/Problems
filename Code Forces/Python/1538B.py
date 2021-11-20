for _TT in range(int(input())):
    n = int(input())
    A = [int(a) for a in input().split(' ')]
    sm = sum(A)
    av = 0
    if sm != 0: av = sm//n
    sol_exists = sm == 0 or (av*n==sm and sm%av==0)
    abv = 0
    for a in A: 
        if a > av: abv += 1
    print(abv) if sol_exists else print('-1')
