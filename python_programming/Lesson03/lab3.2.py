
start = int(input())
thend = int(input())

one = min(start, thend)
two = max(start, thend)

sum = 0
for x in range(one, two+1):
    if x % 2 != 0:
        sum += x

print(sum)