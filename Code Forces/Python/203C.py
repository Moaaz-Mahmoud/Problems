line1 = input()
line1 = line1.split(' ')
n = int(line1[0])
d = int(line1[1])
line2 = input()
line2 = line2.split(' ')
a = int(line2[0])
b = int(line2[1])

clients = []
for i in range(0, n):
    linei = input()
    linei = linei.split(' ')
    clients.append( a*int(linei[0]) + b*int(linei[1]) )
clients.sort()

c_count = 0
while(1):
    d -= clients[i]
    if(d < 0):
        break
    c_count += 1

print(c_count)