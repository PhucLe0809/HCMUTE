n = int(input())

flower = []
for i in range(0, n):
    x = input()
    flower.append(x)

mid = int(n/2)
f1 = flower[0:mid]
f2 = flower[mid:n]
for x in f1:
    print(x, sep = ' ', end = ' ')    
print(sep = '\n', end = '\n')

for x in f2:
    print(x, sep = ' ', end = ' ')
print(sep = '\n', end = '\n')    
    
for x in f1:
    print(len(x), sep = ' ', end = ' ')    
print(sep = '\n', end = '\n')

for x in f2:
    print(len(x), sep = ' ', end = ' ')
    