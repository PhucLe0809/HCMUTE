a = float(input("Enter Math scores is "))
b = float(input("Enter Physics scores is "))
c = float(input("Enter Chemistry scores is "))

print("Math scores is", a)
print("Physics scores is", b)
print("Chemistry scores is", c)

aver = (a + b + c) / 3.0
print("Average scores is", aver)

if (aver <= 5.0):
    print("Fighting!!!")
    exit()
if (aver <= 6.0):
    print("Medium!")
    exit()
if (aver <= 7.0):
    print("Well!")
    exit()
if (aver <= 8.0):
    print("Good!")
    exit()
print("Excellent!")