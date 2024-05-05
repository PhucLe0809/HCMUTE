n = int(input())
inp = []

for i in range(0, n):
    x = int(input())
    inp.append(x)

res = -1
for i in range(0, n):
    if inp[i] > 0: 
        res = i

print(res)