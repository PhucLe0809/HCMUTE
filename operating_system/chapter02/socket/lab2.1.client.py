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
        while True:
            # Nhập các hệ số a, b, c từ người dùng
            a = input("Nhập hệ số a: ")
            b = input("Nhập hệ số b: ")
            c = input("Nhập hệ số c: ")

            # Gửi dữ liệu cho server
            send_data(client_socket, f"{a},{b},{c}")

            # Nhận kết quả từ server
            result = receive_data(client_socket)
            print("Kết quả từ server:", result)

            # Hỏi người dùng có muốn tiếp tục hay không
            choice = input("Tiếp tục? (yes/no): ")
            if choice.lower() != 'yes':
                break

    finally:
        # Đóng kết nối
        client_socket.close()

if __name__ == "__main__":
    main()
