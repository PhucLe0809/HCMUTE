old = float(input("Old index is "))
new = float(input("New index is "))

print("Old index is", old)
print("New index is", new)

per = new - old
cost = 0
if (per <= 50.0):
    cost += per * 1000
if (per > 50.0 and per <= 100):
    cost += 50.0 * 1000
    cost += (per - 50.0) * 2000
if (per > 100):
    cost += 50.0 * 1000 + 50.0 * 2000
    cost += (per - 100) * 3500

print("Cost is", cost)