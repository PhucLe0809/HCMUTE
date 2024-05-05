m = int(input("Enter month is "))

if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12):
    print("The month has 31 days")
    exit()
if (m == 4 or m == 6 or m == 9 or m == 11):
    print("The month has 30 days")
    exit()
    
print("The month has 28 days")