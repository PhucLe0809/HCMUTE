a = int(input("Enter hours is "))
b = int(input("Enter minutes is "))
c = int(input("Enter seconds is "))

calc = a*3600 + b*60 + c
calc += 1

h = (calc // (3600)) % 24
calc %= 3600
m = calc // (60)
calc %= 60
s = calc

print("Next time is", h,":", m, ":", s)