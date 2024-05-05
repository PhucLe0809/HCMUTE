n = int(input())
key = int(input())
inp = []

for i in range(0, n):
    x = int(input())
    inp.append(x)
    
flag = False
cnt = 0
lower = []
upper = []
for x in inp:
    flag = flag or (x == key)
    if x == key:
        cnt += 1
    if x < key:
        lower.append(x)
    if x > key:
        upper.append(x)
        
if flag:
    print('Yes')
else:
    print('No')
print(cnt)
for x in lower:
    print(x, sep = ' ', end = ' ')
print()
for x in upper:
    print(x, sep = ' ', end = ' ')