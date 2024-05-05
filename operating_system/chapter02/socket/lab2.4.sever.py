import socket
import threading

class StringHandler:
    def __init__(self):
        pass

    def to_upper(self, s):
        return s.upper()

    def to_lower(self, s):
        return s.lower()

    def delete_substring(self, s, substring):
        return s.replace(substring, '')

    def insert_substring(self, s, substring, index):
        return s[:index] + substring + s[index:]

def handle_client(client_socket):
    string_handler = StringHandler()

    while True:
        try:
            # Nhận yêu cầu từ client
            request = client_socket.recv(1024).decode()
            if not request:
                break

            # Phân tích yêu cầu từ client thành lệnh và các tham số
            parts = request.split(';')
            command = parts[0].strip().upper()
            params = parts[1:]

            # Thực hiện xử lý chuỗi dựa trên lệnh và các tham số
            if command == 'UPPER':
                result = string_handler.to_upper(*params)
            elif command == 'LOWER':
                result = string_handler.to_lower(*params)
            elif command == 'DELETE':
                result = string_handler.delete_substring(*params)
            elif command == 'INSERT':
                if len(params) == 3:
                    substring, index = params[:2]
                    if index.isdigit():
                        index = int(index)
                        result = string_handler.insert_substring(substring, index)
                    else:
                        result = "Vị trí cần chèn phải là một số nguyên"
                else:
                    result = "Sai số lượng tham số cho lệnh INSERT"
            else:
                result = "Lệnh không hợp lệ"

            # Gửi kết quả về cho client
            client_socket.send(result.encode())
        except Exception as e:
            print("Lỗi khi xử lý yêu cầu:", e)
            break

    # Đóng kết nối với client khi client đóng kết nối
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

        # Xử lý kết nối của client trong một luồng riêng biệt
        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

if __name__ == "__main__":
    main()
