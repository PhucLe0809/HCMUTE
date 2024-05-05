a = float(input("Enter number is "))
b = float(input("Enter number is "))
c = float(input("Enter number is "))

if ((a + b <= c) or (a + c <= b) or (b + c <= a)):
    print("Invalid value!")
    exit()

one = False
if (a == b or a == c or b == c):
    one = True
      
two = False
if (a == b and b == c):
    two = True
    
three = False
if ((a**2 + b**2 == c**2) or (a**2 + c**2 == b**2) or (b**2 + c**2 == a**2)):
    three = True
    
if (two == True):
    print("Tam giac deu")
    exit()
if (one == True and three == True):
    print("Tam giac vuong can")
    exit()
if (one == True):
    print("Tam giac can")
    exit()
if (three == True):
    print("Tam giac vuong")
    exit()

print("Tam giac thuong")