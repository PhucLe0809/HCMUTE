import random

def initialize_list(n):
    return [random.randint(1, 100) for _ in range(n)]

def remove_elements(lst, k):
    lst = [x for x in lst if x != k]
    return lst

def is_symmetric(lst):
    return lst == lst[::-1]

n = int(input("Enter the number of elements: "))
my_list = initialize_list(n)
print("Initialized list:", my_list)

k = int(input("Enter the value to remove: "))
my_list = remove_elements(my_list, k)
print("List after removing elements with value", k, ":", my_list)

if is_symmetric(my_list):
    print("The list is symmetric.")
else:
    print("The list is not symmetric.")
