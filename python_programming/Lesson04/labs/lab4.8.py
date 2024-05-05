n = int(input())
inp = []

for i in range(0, n):
    x = int(input())
    inp.append(x)
    
id = -1
for i in range(0, n):
    if inp[i] < 0:
        id = i
        break

print(id)