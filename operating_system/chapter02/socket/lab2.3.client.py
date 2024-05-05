import socket

def send_data(client_socket, data):
    # Gửi dữ liệu cho server
    client_socket.send(data.encode())

def receive_data(client_socket):
    # Nhận dữ liệu từ server
    data_received = client_socket.recv(1024).decode()
    return data_received

def main():
    # Tạo một socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Kết nối đến server
    client_socket.connect(('127.0.0.1', 12345))

    try:
        # Nhập tên file, chuỗi s1 và s2 từ người dùng
        filename = input("Nhập tên file: ")
        s1 = input("Nhập chuỗi s1: ")
        s2 = input("Nhập chuỗi s2: ")

        # Gửi dữ liệu cho server
        send_data(client_socket, f"{filename};{s1};{s2}")

        # Nhận file kết quả từ server
        result = receive_data(client_socket)
        print("File kết quả:")
        print(result)

    finally:
        # Đóng kết nối
        client_socket.close()

if __name__ == "__main__":
    main()
