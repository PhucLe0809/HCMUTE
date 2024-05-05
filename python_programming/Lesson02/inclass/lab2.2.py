a = int(input("Enter number is "))
b = int(input("Enter number is "))
c = int(input("Enter number is "))

max = a
if (a < b):
    max = b
if (max < c):
    max = c

min = a
if (a > b):
    min = b
if (min > c):
    min = c

print("Maximum value is", max)
print("Minimum value is", min)
    