import socket
import math

def solve_quadratic_equation(a, b, c):
    # Giải phương trình bậc 2
    delta = b**2 - 4*a*c
    if delta < 0:
        return "Phương trình không có nghiệm thực"
    elif delta == 0:
        x = -b / (2*a)
        return f"Nghiệm kép: x = {x}"
    else:
        x1 = (-b + math.sqrt(delta)) / (2*a)
        x2 = (-b - math.sqrt(delta)) / (2*a)
        return f"Nghiệm 1: x1 = {x1}, Nghiệm 2: x2 = {x2}"

def handle_client_connection(client_socket, client_address):
    while True:
        # Nhận dữ liệu từ client
        data = client_socket.recv(1024).decode()
        if not data:
            break  # Nếu không có dữ liệu, thoát khỏi vòng lặp
        print(f"Dữ liệu nhận được từ client {client_address}: {data}")

        # Phân tích dữ liệu nhận được thành 3 số a, b, c
        try:
            a, b, c = map(float, data.split(','))
        except ValueError:
            client_socket.send("Dữ liệu không hợp lệ".encode())
            continue

        # Giải phương trình bậc 2
        result = solve_quadratic_equation(a, b, c)

        # Gửi kết quả về cho client
        client_socket.send(result.encode())

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
