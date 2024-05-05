import mysql.connector
from datetime import datetime

# create connection to MySQL
mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="123456789",
  database = "mywebsite"
)

sql = """INSERT INTO post(post_author, post_title, post_content, post_date)
          VALUES (%s, %s, %s, %s)
      """
now = datetime.now()
formatted_datetime = now.strftime('%Y-%m-%d %H:%M:%S')
val = ("Phong Đoàn", "Tiêu đề bài viết", "Nội dung bài viết", formatted_datetime)
mycursor = mydb.cursor()
mycursor.execute(sql, val)
mydb.commit()

# Chạy nhiều lệnh cùng lúc
sql = """INSERT INTO post(post_author, post_title, post_content, post_date) 
          VALUES (%s, %s, %s, %s)
      """

val = [
        ("Phong Đoàn", "Tiêu đề bài viết", "Nội dung bài viết", "2024-04-20 19:46:05"),
        ("Phong Đoàn", "Tiêu đề bài viết", "Nội dung bài viết", "2024-04-20 19:47:06"),
        ("Phong Đoàn", "Tiêu đề bài viết", "Nội dung bài viết", "2024-04-20 19:48:07"),
        ("Phong Đoàn", "Tiêu đề bài viết", "Nội dung bài viết", "2024-04-20 19:49:08"),
        ("Phong Đoàn", "Tiêu đề bài viết", "Nội dung bài viết", "2024-04-20 19:50:09")
      ]

mycursor.executemany(sql, val)
mydb.commit()
print(mycursor.rowcount, "record(s) was inserted.")

# disconnect from MySQL
mydb.close()