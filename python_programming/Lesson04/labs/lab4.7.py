n = int(input())
inp = []

for i in range(0, n):
    x = int(input())
    inp.append(x)
    
sum = 0
for x in inp:
    if (x > 0):
        sum += x

print(sum)