import re

def check_password(password):
    if len(password) < 10:
        return False
    
    if not re.search(r"[A-Z]", password):
        return False
    if not re.search(r"[a-z]", password):
        return False
    if not re.search(r"\d", password):
        return False
    if not re.search(r"[!@#$%^&*()\-_=+{};:,<.>]", password):
        return False
    
    return True

def main():
    while True:
        password = input("Nhập mật khẩu: ")
        if check_password(password):
            print("Mật khẩu hợp lệ!")
            break
        else:
            print("Mật khẩu không đủ mạnh! Hãy thử lại.")

if __name__ == "__main__":
    main()
