def count_char_occurrences(string, char):
    return sum(map(lambda x: 1 if x == char else 0, string))

def main():
    input_string = input("Nhập vào chuỗi: ")
    input_char = input("Nhập vào ký tự cần đếm: ")

    count = count_char_occurrences(input_string, input_char)
    print(f"Số lần xuất hiện của ký tự '{input_char}' trong chuỗi là: {count}")

if __name__ == "__main__":
    main()
