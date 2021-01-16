def print_rangoli(n):
    # your code goes here
    for i in range(1, n + 1):
        for j in range(2 * (n-i)):
            print('-', end='')
    
        maxC = chr(ord('a') + n - 1)
        j_ = 1
        if i != 1:
            for j in range(ord(maxC), ord(maxC) - i, -1):
                print(chr(j), '-', sep='', end='')
                j_ = j
        else:
            for j in range(ord(maxC), ord(maxC) - i, -1):
                print(chr(j), sep='', end='')
                j_ = j
        for j in range(j_ + 1, j_ + i):
            print(chr(j), sep='', end='')
            if j != j_ + i - 1:
                print('-', end='')
                    
        for j in range(2 * (n-i)):
            print('-', end='')
        print()
    
        
    for i in range(n-1, 0, -1):
        for j in range(2 * (n-i)):
            print('-', end='')
            
        maxC = chr(ord('a') + n - 1)
        j_ = 1
        if i != 1:
            for j in range(ord(maxC), ord(maxC) - i, -1):
                print(chr(j), '-', sep='', end='')
                j_ = j
        else:
            for j in range(ord(maxC), ord(maxC) - i, -1):
                print(chr(j), sep='', end='')
                j_ = j
        for j in range(j_ + 1, j_ + i):
            print(chr(j), sep='', end='')
            if j != j_ + i - 1:
                print('-', end='')
            
        for j in range(2 * (n-i)):
            print('-', end='')
        print()
