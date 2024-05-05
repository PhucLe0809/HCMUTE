import socket

class FileHandler:
    def __init__(self):
        self.file = None

    def open_file(self, filename):
        try:
            self.file = open(filename, 'r')
            return True
        except FileNotFoundError:
            return False

    def next_line(self):
        return self.file.readline()

    def close_file(self):
        self.file.close()

    def replace(self, s, s1, s2):
        content = self.file.read()
        replaced_content = content.replace(s1, s2)
        self.file.close()
        self.file = open(s, 'w')
        self.file.write(replaced_content)
        self.file.close()
        return replaced_content

def handle_client_connection(client_socket, client_address):
    file_handler = FileHandler()

    while True:
        # Nhận dữ liệu từ client
        data = client_socket.recv(1024).decode()
        if not data:
            break  # Nếu không có dữ liệu, thoát khỏi vòng lặp

        # Phân tích dữ liệu nhận được từ client thành tên file, s1, và s2
        filename, s1, s2 = data.split(';')
        filename = filename.strip()
        s1 = s1.strip()
        s2 = s2.strip()

        # Mở file và thực hiện thay thế
        if file_handler.open_file(filename):
            replaced_content = file_handler.replace(filename, s1, s2)
            file_handler.close_file()
            client_socket.send(replaced_content.encode())
        else:
            client_socket.send("File không tồn tại".encode())

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
