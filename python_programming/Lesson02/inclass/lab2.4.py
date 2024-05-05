# a*x + b = 0
a = float(input("Enter number is "))
b = float(input("Enter number is "))

if (a == 0 and b != 0):
    print("The equation has no solution!")
    exit()
    
if (a == 0 and b == 0):
    print("Equation with countless solutions!")
    exit()
   
x = -b / a
x = round(x, 9)
print("Equation is", x)