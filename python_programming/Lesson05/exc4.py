import random

def create_unique_list(n):
    unique_list = []
    while len(unique_list) < n:
        num = random.randint(1, 10 * n)
        if num not in unique_list:
            unique_list.append(num)
    return unique_list

n = int(input("Enter the number of unique elements: "))
unique_list = create_unique_list(n)
print("Unique list:", unique_list)
