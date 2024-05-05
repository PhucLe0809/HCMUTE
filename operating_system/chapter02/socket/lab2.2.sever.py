import socket
import numpy as np

def multiply_matrices(matrix1, matrix2):
    # Chuyển ma trận từ list sang numpy array để thực hiện phép nhân ma trận
    matrix1_np = np.array(matrix1)
    matrix2_np = np.array(matrix2)

    # Thực hiện phép nhân ma trận
    result = np.dot(matrix1_np, matrix2_np)

    # Chuyển kết quả từ numpy array về list để gửi về cho client
    return result.tolist()

def handle_client_connection(client_socket, client_address):
    while True:
        # Nhận dữ liệu từ client
        data = client_socket.recv(4096).decode()
        if not data:
            break  # Nếu không có dữ liệu, thoát khỏi vòng lặp
        print(f"Dữ liệu nhận được từ client {client_address}: {data}")

        # Phân tích dữ liệu nhận được thành 2 ma trận và kích thước
        try:
            matrix_data = data.split(';')
            size1, matrix1_data = matrix_data[0].split(':')
            size2, matrix2_data = matrix_data[1].split(':')
            
            m1, n1 = map(int, size1.split('x'))
            m2, n2 = map(int, size2.split('x'))
            
            matrix1 = [list(map(int, row.split(','))) for row in matrix1_data.split('|')]
            matrix2 = [list(map(int, row.split(','))) for row in matrix2_data.split('|')]
            
            if n1 != m2:
                raise ValueError("Kích thước của hai ma trận không hợp lệ")
                
        except ValueError as e:
            client_socket.send(str(e).encode())
            continue

        # Tính tích của 2 ma trận
        result = multiply_matrices(matrix1, matrix2)

        # Gửi kết quả về cho client
        client_socket.send(str(result).encode())

    # Đóng kết nối với client
    print("Ngắt kết nối từ:", client_address)
    client_socket.close()

def main():
    # Tạo một socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Lắng nghe kết nối tại cổng 12345
    server_socket.bind(('127.0.0.1', 12345))
    server_socket.listen(5)

    print("Server đang lắng nghe...")

    while True:
        # Chấp nhận kết nối từ client
        client_socket, client_address = server_socket.accept()
        print(f"Kết nối từ: {client_address}")

        # Xử lý kết nối của client trong một thread riêng biệt
        handle_client_connection(client_socket, client_address)

if __name__ == "__main__":
    main()
