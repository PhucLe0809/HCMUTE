import threading
import time

NUM_READERS = 5  # Số lượng người đọc
NUM_WRITERS = 2  # Số lượng người viết

# Semaphore để kiểm soát số lượng người đọc và người viết được phép truy cập đồng thời
reader_lock = threading.Semaphore(1)  # Semaphore cho người đọc
writer_lock = threading.Semaphore(1)  # Semaphore cho người viết

# Biến để theo dõi số lượng người đọc đang đọc
readers_count = 0

# Hàm đại diện cho hành động của người đọc
def reader(reader_id):
    global readers_count
    while True:
        time.sleep(1)
        
        # Kiểm tra và cập nhật trạng thái của người đọc
        reader_lock.acquire()
        readers_count += 1
        if readers_count == 1:
            writer_lock.acquire()  # Khóa người viết nếu đây là người đọc đầu tiên
        reader_lock.release()

        # Người đọc đang đọc
        print(f'Reader {reader_id} is reading.\n')

        # Cập nhật trạng thái của người đọc
        reader_lock.acquire()
        readers_count -= 1
        if readers_count == 0:
            writer_lock.release()  # Giải phóng khóa của người viết nếu không còn người đọc
        reader_lock.release()

# Hàm đại diện cho hành động của người viết
def writer(writer_id):
    while True:
        time.sleep(2)
        
        # Người viết chờ khi không có người đọc hoặc người viết khác
        writer_lock.acquire()
        print(f'Writer {writer_id} is writing.\n')
        writer_lock.release()

# Tạo và khởi động các luồng cho người đọc và người viết
reader_threads = [threading.Thread(target=reader, args=(i,)) for i in range(NUM_READERS)]
writer_threads = [threading.Thread(target=writer, args=(i,)) for i in range(NUM_WRITERS)]

for reader_thread in reader_threads:
    reader_thread.start()

for writer_thread in writer_threads:
    writer_thread.start()

# Chờ tất cả các luồng kết thúc
for reader_thread in reader_threads:
    reader_thread.join()

for writer_thread in writer_threads:
    writer_thread.join()
