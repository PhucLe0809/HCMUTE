def sort_descending(numbers):
    return sorted(numbers, reverse=True)

def input_float_list():
    while True:
        try:
            n = int(input("Enter the number of elements: "))
            if n <= 0:
                print("Number of elements should be positive. Please try again.")
                continue
            numbers = []
            for i in range(n):
                num = float(input(f"Enter number {i+1}: "))
                numbers.append(num)
            return numbers
        except ValueError:
            print("Invalid input. Please enter numbers.")

print("Enter a list of floating-point numbers:")
float_list = input_float_list()
sorted_list = sort_descending(float_list)
print("Sorted list (descending):", sorted_list)
