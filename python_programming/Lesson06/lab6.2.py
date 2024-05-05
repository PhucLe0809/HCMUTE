def dec_to_hex(decimal):
    hex_chars = "0123456789ABCDEF"
    hex_result = ""
    
    if decimal == 0:
        return "0"
    
    while decimal > 0:
        remainder = decimal % 16
        hex_result = hex_chars[remainder] + hex_result
        decimal = decimal // 16
    
    return hex_result

def main():
    decimal = int(input("Nhập số thập phân cần chuyển đổi: "))
    hex_result = dec_to_hex(decimal)
    print("Kết quả sau khi chuyển đổi sang hệ 16 là:", hex_result)

if __name__ == "__main__":
    main()
