n = int(input())
next = n
snacks = [False] * (n+2)
orderedSnacks = [0]*(n+2)
 
orderedSnacks = list(input().split(' '))
for i in range(0, n):
    orderedSnacks[i] = int(orderedSnacks[i])
 
for i in range(1, n+1):
    inSnack = orderedSnacks[i-1]
    snacks[inSnack] = True
    if(inSnack == next):
        snacks[next] = False
        print(next, ' ', sep='', end='')
        next = next - 1
        for next in range(next, 0, -1):
            if(snacks[next] == True):
                print(next, ' ', end='')
                next = next - 1
            else:
                break
    print('')
