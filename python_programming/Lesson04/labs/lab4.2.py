n = int(input())
inp = []
odd = 0

for i in range(0, n):
    x = int(input())
    if (x % 2 != 0):
        odd += x
    inp.append(x)

for x in inp:
    if (x % 2 == 0):
        print(x, sep = ' ', end = ' ')
        
print(sep = '\n', end = '\n')
print(odd)    
    