a = int(input("Enter number is "))
b = int(input("Enter number is "))
c = int(input("Enter number is "))

if (a > b):
    x = a
    a = b
    b = x
if (b > c):
    x = b
    b = c
    c = x
if (a > b):
    x = a
    a = b
    b = x

print("Less order", a, "<", b, "<", c)
print("Greater order", c, ">", b, ">", a)