base = float(input("Enter base salary is "))
hour = float(input("Enter hours work is "))

salary = 0.0
if (hour >= 0.0 and hour <= 35.0):
    salary = base
else:
    salary = base * 1.5

print("Salary is", salary)