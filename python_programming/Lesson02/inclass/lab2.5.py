import math

# a*x^2 + b*x + c = 0
a = float(input("Enter number is "))
b = float(input("Enter number is "))
c = float(input("Enter number is "))

if (a == 0):
    if (b == 0 and c != 0):
        print("The equation has no solution!")
        exit()
        
    if (b == 0 and c == 0):
        print("Equation with countless solutions!")
        exit()
    
    x = -c / b
    x = round(x, 9)
    print("Equation is", x)
else:
    delta = b*b - 4*a*c
    
    if (delta < 0):
        print("The equation has no solution!")
        exit()
        
    if (delta == 0):
        x = -b / (2*a)
        x = round(x, 9)
        print("Equation is", x)
    else:
        x1 = (-b + math.sqrt(delta)) / (2*a)
        x2 = (-b - math.sqrt(delta)) / (2*a)
        x1 = round(x1, 9)
        x2 = round(x2, 9)
        print("Equation is", x1)
        print("Equation is", x2)
        