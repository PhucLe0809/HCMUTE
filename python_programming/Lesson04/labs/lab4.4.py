n = int(input())
a = set()
for i in range(0, n):
    x = int(input())
    a.add(x)

m = int(input())
b = set()
for i in range(0, m):
    x = int(input())
    b.add(x)
    
k = int(input())
c = set()
for i in range(0, k):
    x = int(input())
    c.add(x)

d = a | b | c
for x in d:
    print(x, sep = ' ', end = ' ')
print(sep = '\n', end = '\n')

e = a & b & c
for x in e:
    print(x, sep = ' ', end = ' ')
print(sep = '\n', end = '\n')

f = a - b
for x in f:
    print(x, sep = ' ', end = ' ')
print(sep = '\n', end = '\n')

g = a ^ b
for x in f:
    print(x, sep = ' ', end = ' ')
print(sep = '\n', end = '\n')