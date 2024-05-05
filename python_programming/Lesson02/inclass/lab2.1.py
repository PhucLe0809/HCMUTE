num = int(input("Enter your number: "))

if (num < 100 or num > 999):
    print("Invalid value!")
else:
    res = 0
    res += int(num % 10)
    res += int((num // 10) % 10)
    res += int(num // 100)
    print("Sum digit of", num, "is", res)