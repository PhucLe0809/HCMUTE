import socket

def send_request(client_socket, request):
    # Gửi yêu cầu đến server
    client_socket.send(request.encode())

    # Nhận kết quả từ server
    response = client_socket.recv(1024).decode()
    print("Kết quả từ server:", response)

def delete_input():
    # Nhập chuỗi ban đầu và chuỗi cần xóa
    param1 = input("Nhập chuỗi ban đầu: ")
    param2 = input("Nhập chuỗi cần xóa: ")
    return param1, param2

def insert_input():
    # Nhập chuỗi ban đầu, chuỗi cần chèn và vị trí cần chèn
    param1 = input("Nhập chuỗi ban đầu: ")
    param2 = input("Nhập chuỗi cần chèn: ")
    index = input("Nhập vị trí cần chèn (index): ")
    return param1, param2, index

def main():
    # Tạo một socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Kết nối đến server
    client_socket.connect(('127.0.0.1', 12345))

    try:
        # Nhập lệnh từ người dùng
        command = input("Nhập lệnh (UPPER, LOWER, DELETE, INSERT): ").upper()

        # Gửi yêu cầu đến server tùy thuộc vào lệnh nhập
        if command in ['UPPER', 'LOWER']:
            param = input("Nhập chuỗi: ")
            request = f"{command};{param}"
        elif command == 'DELETE':
            param1, param2 = delete_input()
            request = f"{command};{param1};{param2}"
        elif command == 'INSERT':
            param1, param2, index = insert_input()
            request = f"{command};{param1};{param2};{index}"
        else:
            print("Lệnh không hợp lệ")
            return

        # Gửi yêu cầu đến server
        send_request(client_socket, request)

    finally:
        # Đóng kết nối
        client_socket.close()

if __name__ == "__main__":
    main()
