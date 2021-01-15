def shuffle(s):
    ans = s[0] + s[2] + s[4] + s[3] + s[1]
    return ans


s = input()
s = shuffle(s)
s = int(s)
s = s**5
s = str(s)
a = int(len(s)) - 5
b = int(len(s))
for i in range(a, b):
    print(s[i], sep='', end='')

#12345