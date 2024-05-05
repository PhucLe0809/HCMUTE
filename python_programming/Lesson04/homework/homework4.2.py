inp = []

while True:
    print('Enter number (enter .break. to exit) :', sep = ' ', end = ' ')
    x = input()
    if (x == 'break'):
        break
    inp.append(int(x))
    
for x in inp:
    print(x, sep = ' ', end = ' ')
print()

def is_prime(num):
    if (num < 2):
        return False
    i = 2
    while (i*i <= num):
        if num % i == 0:
            return False
        else:
            i += 1
            
    return True

for x in inp:
    if is_prime(x):
        print(x, sep = ' ', end = ' ')
print()

pos = []
neg = []
for x in inp:
    if x > 0: 
        pos.append(x)
    if x < 0:
        neg.append(x)
sumpos = float(sum(pos))
sumneg = float(sum(neg))
avgpos = (sumpos / len(pos)) if (len(pos) > 0) else -1
avgneg = (sumneg / len(neg)) if (len(neg) > 0) else -1
print(avgpos)
print(avgneg)

even = []
odd = []
for x in inp:
    if x % 2 == 0: 
        even.append(x)
    else:
        odd.append(x)
print(max(even))
print(min(odd))

n = len(inp)
for i in range(0, n-1):
    for j in range(i+1, n):
        if (inp[i] > inp[j]):
            x = inp[i]
            inp[i] = inp[j]
            inp[j] = x
for x in inp:
    print(x, sep = ' ', end = ' ')