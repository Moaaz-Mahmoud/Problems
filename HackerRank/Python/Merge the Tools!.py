from collections import defaultdict

def merge_the_tools(string, k):
    # your code goes here
    #s = input()
    #k = int(input())
    s = string
    n = len(s)
    i = 0
    
    if k == 1:
        for c in s:
            print(c)
    else:
        while i < n:
            D = defaultdict(int)
            if D[s[i]] == 0:
                print(s[i], end = '')
            D[s[i]] += 1
            i += 1
            while i%k != 0:
                if D[s[i]] == 0:
                    print(s[i], end = '')
                    
                D[s[i]] += 1
                i += 1
            print()
