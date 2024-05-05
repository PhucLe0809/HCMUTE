import socket

def send_message(client_socket, message):
    # Gửi tin nhắn đến server
    client_socket.send(message.encode())

    # Nhận phản hồi từ server
    response = client_socket.recv(1024).decode()
    print("Server:", response)

def main():
    # Tạo một socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Kết nối đến server
    client_socket.connect(('127.0.0.1', 12345))

    try:
        while True:
            # Nhập tin nhắn từ người dùng và gửi đến server
            message = input("Nhập tin nhắn: ")
            send_message(client_socket, message)

            # Hỏi người dùng có muốn tiếp tục gửi tin nhắn hay không
            choice = input("Tiếp tục gửi tin nhắn? (yes/no): ")
            if choice.lower() != 'yes':
                break

    finally:
        # Đóng kết nối
        client_socket.close()

if __name__ == "__main__":
    main()
