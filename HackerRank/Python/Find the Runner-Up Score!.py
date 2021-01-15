if __name__ == '__main__':
    n = int(input())
    A = input().split()
    for i in range(0, len(A)):
        A[i] = int(A[i])

    mx1, mx2 = -101, -101
    for a in A:
        if a > mx1:
            mx1 = a

    for a in A:
        if a == mx1:
            continue
        elif a > mx2:
            mx2 = a
            
    print(mx2)
    
