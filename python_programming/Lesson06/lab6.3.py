def dec_to_oct(decimal):
    octal_result = ""
    
    if decimal == 0:
        return "0"
    
    while decimal > 0:
        remainder = decimal % 8
        octal_result = str(remainder) + octal_result
        decimal = decimal // 8
    
    return octal_result

def main():
    decimal = int(input("Nhập số thập phân cần chuyển đổi: "))
    octal_result = dec_to_oct(decimal)
    print("Kết quả sau khi chuyển đổi sang hệ 8 là:", octal_result)

if __name__ == "__main__":
    main()
