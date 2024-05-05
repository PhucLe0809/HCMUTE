
# x + y = 36
# 2x + 4y = 100
# 2x + 2y = 72
# 2y = 28 --> y = 14
# x = 36 - 14 = 22

for x in range(0, 37):
    for y in range(0, 37):
        if (x + y == 36 and 2*x + 4*y == 100):
            print(x, y)