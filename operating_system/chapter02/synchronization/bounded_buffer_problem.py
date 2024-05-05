import threading
import time
import random

# Kích thước của buffer
BUFFER_SIZE = 5

# Mutex (Khóa) để truy cập vào buffer
mutex = threading.Lock()

# Semaphore để điều khiển việc truy cập vào buffer
empty = threading.Semaphore(BUFFER_SIZE)
full = threading.Semaphore(0)

# Buffer
buffer = []

# Hàm Producer
def producer():
    global buffer
    while True:
        item = random.randint(1, 100)  # Tạo một phần tử ngẫu nhiên
        empty.acquire()  # Chờ một chỗ trống trong buffer
        mutex.acquire()  # Chiếm lock trước khi truy cập vào buffer
        buffer.append(item)  # Thêm phần tử vào buffer
        print(f"Sản xuất phần tử: {item}, Buffer: {buffer}")
        mutex.release()  # Giải phóng lock
        full.release()  # Thông báo rằng buffer đã đầy
        time.sleep(random.uniform(0.1, 0.5))  # Giả lập thời gian xử lý

# Hàm Consumer
def consumer():
    global buffer
    while True:
        full.acquire()  # Chờ buffer trở thành không rỗng
        mutex.acquire()  # Chiếm lock trước khi truy cập vào buffer
        item = buffer.pop(0)  # Loại bỏ phần tử từ buffer
        print(f"Tiêu thụ phần tử: {item}, Buffer: {buffer}")
        mutex.release()  # Giải phóng lock
        empty.release()  # Thông báo rằng buffer không còn đầy nữa
        time.sleep(random.uniform(0.1, 0.5))  # Giả lập thời gian xử lý

# Tạo các luồng Producer và Consumer
producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)

# Khởi động các luồng
producer_thread.start()
consumer_thread.start()

# Kết thúc các luồng
producer_thread.join()
consumer_thread.join()
