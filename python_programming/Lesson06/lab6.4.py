from functools import reduce

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]

odd_numbers = filter(lambda x: x % 2 != 0, numbers)
sum_of_odd_numbers = reduce(lambda x, y: x + y, odd_numbers, 0)

print("Tổng các số lẻ trong list là:", sum_of_odd_numbers)
