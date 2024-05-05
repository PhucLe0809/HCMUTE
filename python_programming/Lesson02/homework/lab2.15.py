h = int(input("Enter Hour is "))
m = int(input("Enter Minute is "))
s = int(input("Enter Second is "))

if (h < 0 or h > 23 or m < 0 or m > 59 or s < 0 or s > 59):
    print("Invalid value!")
else:
    print("Valid value!")