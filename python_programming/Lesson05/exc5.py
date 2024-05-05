def input_sorted_sequence():
    while True:
        sequence = input("Enter a sequence of numbers separated by spaces (in increasing order): ")
        sequence = sequence.strip().split()
        
        try:
            sequence = [int(num) for num in sequence]
            if all(sequence[i] <= sequence[i + 1] for i in range(len(sequence) - 1)):
                return sequence
            else:
                print("The sequence is not in increasing order. Please try again.")
        except ValueError:
            print("Invalid input. Please enter numbers separated by spaces.")

print("Please enter a sequence of numbers in increasing order:")
sorted_sequence = input_sorted_sequence()
print("Sorted sequence:", sorted_sequence)
