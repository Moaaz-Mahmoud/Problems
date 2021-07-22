for _TT in range(int(input())):
    n = int(input())
    A = [int(a) for a in input().split(' ')]
    mndx = A.index(min(A))+1
    mxdx = A.index(max(A))+1
    s1 = max(mndx, mxdx)
    s2 = mndx + n-mxdx+1
    s3 = n-mndx+1 + mxdx
    s4 = max(n-mndx+1, n-mxdx+1)
    print(min(s1, s2, s3, s4))
