import socket

def send_data(client_socket, data):
    # Gửi dữ liệu cho server
    client_socket.send(data.encode())

def receive_data(client_socket):
    # Nhận dữ liệu từ server
    data_received = client_socket.recv(4096).decode()
    return data_received

def main():
    # Tạo một socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Kết nối đến server
    client_socket.connect(('127.0.0.1', 12345))

    try:
        while True:
            # Nhập kích thước và các phần tử của ma trận thứ nhất từ người dùng
            size1 = input("Nhập kích thước của ma trận thứ nhất (dạng mxn): ")
            print("Nhập các phần tử của ma trận thứ nhất:")
            matrix1 = []
            for i in range(int(size1.split('x')[0])):
                row = input(f"Nhập hàng {i+1} (các phần tử cách nhau bằng dấu ','): ")
                matrix1.append(row)
                
            # Nhập kích thước và các phần tử của ma trận thứ hai từ người dùng
            size2 = input("Nhập kích thước của ma trận thứ hai (dạng nxp): ")
            print("Nhập các phần tử của ma trận thứ hai:")
            matrix2 = []
            for i in range(int(size2.split('x')[0])):
                row = input(f"Nhập hàng {i+1} (các phần tử cách nhau bằng dấu ','): ")
                matrix2.append(row)

            # Gửi dữ liệu cho server
            send_data(client_socket, f"{size1}:{'|'.join(matrix1)};{size2}:{'|'.join(matrix2)}")

            # Nhận kết quả từ server
            result = receive_data(client_socket)
            print("Kết quả từ server:")
            print(result)

            # Hỏi người dùng có muốn tiếp tục hay không
            choice = input("Tiếp tục? (yes/no): ")
            if choice.lower() != 'yes':
                break

    finally:
        # Đóng kết nối
        client_socket.close()

if __name__ == "__main__":
    main()
