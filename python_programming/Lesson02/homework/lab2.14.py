d = int(input("Enter Day is "))
m = int(input("Enter Month is "))
y = int(input("Enter Year is "))

if ((y < 0) or (m < 1) or (m > 12)):
    print("Invalid value!")
    exit()
    
res = 0
if ((m == 2) and ((y % 4 == 0 and y % 100 != 0) or (y % 100 == 0 and y % 400 == 0))):
    res = 1
curr = 0
if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12):
    curr = 31
elif (m == 4 or m == 6 or m == 9 or m == 11):
    curr = 30
else:
    curr = 28

if (d >= 1 and d <= curr + res):
    print("Valid value!")
else:
    print("Invalid value!")
