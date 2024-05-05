def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def initialize_list():
    return []

def add_element(lst, element):
    lst.append(element)

def count_occurrences(lst, k):
    return lst.count(k)

def sum_of_primes(lst):
    return sum(num for num in lst if is_prime(num))

def sort_list(lst):
    return sorted(lst)

def clear_list(lst):
    lst.clear()

def input_list():
    lst = []
    n = int(input("Enter the number of elements in the list: "))
    print("Enter the elements:")
    for _ in range(n):
        element = int(input())
        lst.append(element)
    return lst

my_list = input_list()

print("List:", my_list)

k = int(input("Enter the number to count occurrences: "))
print(f"{k} appears {count_occurrences(my_list, k)} times in the list.")

print("Sum of primes in the list:", sum_of_primes(my_list))

sorted_list = sort_list(my_list)
print("Sorted list:", sorted_list)

clear_list(my_list)
print("List after clearing:", my_list)
