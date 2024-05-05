import random

def initialize_matrix(M, N):
    return [[random.randint(1, 100) for _ in range(N)] for _ in range(M)]

def print_row(matrix, row):
    print("Row", row, ":", matrix[row])

def print_column(matrix, col):
    print("Column", col, ":")
    for row in matrix:
        print(row[col])

def find_max(matrix):
    max_element = matrix[0][0]
    for row in matrix:
        for element in row:
            if element > max_element:
                max_element = element
    return max_element

M = int(input("Enter the number of rows: "))
N = int(input("Enter the number of columns: "))

my_matrix = initialize_matrix(M, N)
print("Initialized matrix:")
for row in my_matrix:
    print(row)

row_number = int(input("Enter the row number to print: "))
print_row(my_matrix, row_number)

col_number = int(input("Enter the column number to print: "))
print_column(my_matrix, col_number)

max_element = find_max(my_matrix)
print("Maximum element in the matrix:", max_element)
