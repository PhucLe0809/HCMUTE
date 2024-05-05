
num = 0

def is_prime(n):
    if (n < 2):
        return False
    for i in range(2, n):
        if (i*i > n):
            return True
        if (n % i == 0):
            return False
    return True

while True:
    num = int(input())
    if (100 <= num <= 1000):
        break

for x in range(2, num):
    if (is_prime(x)):
        print(x, sep = ' ', end = ' ')
    
    # flag = True
    # for i in range(2, n):
    #     if (i*i > n):
    #         break
    #     if (n % i == 0):
    #         flag = False
    #         break
    # if (flag == True):
    #     print(n, sep = ' ', end = ' ')