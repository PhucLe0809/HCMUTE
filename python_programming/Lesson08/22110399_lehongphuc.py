import mysql.connector

def connect_to_mysql():
    try:
        connection = mysql.connector.connect(
            host="localhost",
            user="root",
            password="123456789"
        )
        print("Connected successfully !")
        return connection
    except mysql.connector.Error as err:
        print(f"Connection error: {err}")
        return None

def create_database(cursor):
    try:
        cursor.execute("CREATE DATABASE IF NOT EXISTS hrm")
        print("Database 'hrm' created successfully")
    except mysql.connector.Error as err:
        print(f"Database creation error: {err}")

def create_table(cursor):
    try:
        cursor.execute("USE hrm")
        cursor.execute("""CREATE TABLE IF NOT EXISTS Employee (
                          id INT AUTO_INCREMENT PRIMARY KEY,
                          empId INT,
                          fullname VARCHAR(255),
                          email VARCHAR(255),
                          phone VARCHAR(20)
                          )""")
        print("Table 'Employee' created sucessfully")
    except mysql.connector.Error as err:
        print(f"Table creation error: {err}")

def add_employee(cursor, empId, fullname, email, phone):
    try:
        cursor.execute("INSERT INTO Employee (empId, fullname, email, phone) VALUES (%s, %s, %s, %s)",
                       (empId, fullname, email, phone))
        print("Inserted employee sucessfully!")
    except mysql.connector.Error as err:
        print(f"Employee insertion error: {err}")

def display_all_employees(cursor):
    try:
        cursor.execute("SELECT * FROM Employee")
        employees = cursor.fetchall()
        print("LIST EMPLOYEE:")
        for employee in employees:
            print(employee)
    except mysql.connector.Error as err:
        print(f"Employee display error: {err}")

def search_employee_by_name(cursor, name):
    try:
        cursor.execute("SELECT * FROM Employee WHERE fullname LIKE %s", (f"%{name}%",))
        employees = cursor.fetchall()
        if employees:
            print(f"Search results for '{name}':")
            for employee in employees:
                print(employee)
        else:
            print(f"Not found '{name}'.")
    except mysql.connector.Error as err:
        print(f"Employee search error: {err}")

def delete_employee(cursor, empId):
    try:
        cursor.execute("DELETE FROM Employee WHERE empId = %s", (empId,))
        print("Deleted employee successfully!")
    except mysql.connector.Error as err:
        print(f"Emplyee deletion error: {err}")

def main():
    connection = connect_to_mysql()
    if connection:
        cursor = connection.cursor()
        create_database(cursor)
        create_table(cursor)

        while True:
            print("\n========== MENU ==========")
            print("1. Insert employee")
            print("2. Show employee")
            print("3. Search follow name")
            print("4. Delete employee")
            print("5. Exit")

            choice = input("Choose a function (1-5): ")

            if choice == '1':
                empId = int(input("Employee code: "))
                fullname = input("Full name: ")
                email = input("Email: ")
                phone = input("Phone number: ")
                add_employee(cursor, empId, fullname, email, phone)
                connection.commit()
            elif choice == '2':
                display_all_employees(cursor)
            elif choice == '3':
                name = input("Enter employee'name: ")
                search_employee_by_name(cursor, name)
            elif choice == '4':
                empId = int(input("Enter employee code: "))
                delete_employee(cursor, empId)
                connection.commit()
            elif choice == '5':
                print("Exited ...")
                break
            else:
                print("Invalid selection!")

        cursor.close()
        connection.close()

if __name__ == "__main__":
    main()
