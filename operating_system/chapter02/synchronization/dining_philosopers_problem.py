import threading
import time
import random

NUM_PHILOSOPHERS = 5
EATING_TIME = 2  # Thời gian mỗi nhà triết học ăn
THINKING_TIME = 1  # Thời gian mỗi nhà triết học suy nghĩ

# Tạo lock (mutex) để đồng bộ hóa truy cập vào các đĩa ăn
forks = [threading.Lock() for _ in range(NUM_PHILOSOPHERS)]

# Hàm đại diện cho hành động của mỗi nhà triết học
def philosopher(philosopher_id):
    while True:
        # Nhà triết học suy nghĩ
        print(f'Philosopher {philosopher_id} is thinking.\n')
        time.sleep(THINKING_TIME)

        # Nhà triết học muốn ăn
        print(f'Philosopher {philosopher_id} wants to eat.\n')

        # Chọn đĩa bên trái và bên phải
        left_fork = philosopher_id
        right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS

        # Khóa đĩa ăn bên trái và bên phải
        forks[left_fork].acquire()
        forks[right_fork].acquire()

        # Nhà triết học bắt đầu ăn
        print(f'Philosopher {philosopher_id} is eating.\n')
        time.sleep(EATING_TIME)

        # Giải phóng đĩa ăn bên trái và thông báo
        forks[left_fork].release()
        print(f'Philosopher {philosopher_id} released left fork.\n')

        # Giải phóng đĩa ăn bên phải và thông báo
        forks[right_fork].release()
        print(f'Philosopher {philosopher_id} released right fork.\n')

        # Trạng thái của nhà triết học sau khi ăn xong
        print(f'Philosopher {philosopher_id} finished eating.\n')

# Tạo và khởi động các luồng cho các nhà triết học
philosophers = [threading.Thread(target=philosopher, args=(i,)) for i in range(NUM_PHILOSOPHERS)]
for philosopher_thread in philosophers:
    philosopher_thread.start()

# Chờ tất cả các luồng kết thúc
for philosopher_thread in philosophers:
    philosopher_thread.join()
