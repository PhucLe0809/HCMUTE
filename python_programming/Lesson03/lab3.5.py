
# x + y + z = 100
# 5x + 3y + z/3 = 100
# 15x + 9y + z = 300

for x in range(0, 101):
    for y in range(0, 101):
        for z in range(0, 101):
            if (x + y + z == 100 and 15*x + 9*y + z == 300):
                print(x, y, z)