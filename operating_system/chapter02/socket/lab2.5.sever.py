import socket
import threading

def handle_client(client_socket, client_address):
    while True:
        # Nhận tin nhắn từ client
        message = client_socket.recv(1024).decode()
        if not message:
            break
        
        print(f"Tin nhắn từ {client_address}: {message}")
        
        # Phản hồi lại client
        client_socket.send("Tin nhắn đã nhận".encode())

    # Đóng kết nối với client khi client đóng kết nối
    print(f"{client_address} đã ngắt kết nối.")
    client_socket.close()

def main():
    # Tạo một socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Liên kết socket với địa chỉ và cổng
    server_socket.bind(('127.0.0.1', 12345))

    # Lắng nghe kết nối tới socket
    server_socket.listen(5)
    print("Server đang lắng nghe kết nối...")

    while True:
        # Chấp nhận kết nối từ client
        client_socket, client_address = server_socket.accept()
        print(f"Kết nối từ: {client_address}")

        # Tạo một luồng riêng biệt để xử lý kết nối của client
        client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_thread.start()

if __name__ == "__main__":
    main()
