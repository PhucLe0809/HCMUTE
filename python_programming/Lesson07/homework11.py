class Student:
    def __init__(self, mssv, name, city, diem_toan, diem_ly, diem_hoa):
        self.mssv = mssv
        self.name = name
        self.city = city
        self.diem_toan = int(diem_toan)
        self.diem_ly = int(diem_ly)
        self.diem_hoa = int(diem_hoa)

    def display_info(self):
        print("ID:", self.mssv)
        print("Full name:", self.name)
        print("City:", self.city)
        print("Diem Toan:", self.diem_toan)
        print("Diem Ly:", self.diem_ly)
        print("Diem Hoa:", self.diem_hoa)
        print("Average Score:", self.calculate_average_score())
        print("------------------------")

    def calculate_average_score(self):
        return (self.diem_toan + self.diem_ly + self.diem_hoa) / 3


def read_data_from_file(file_name):
    students = []
    with open(file_name, 'r') as file:
        for line in file:
            data = line.strip().split('; ')
            mssv, name, city, diem_toan, diem_ly, diem_hoa = data
            student = Student(mssv, name, city, diem_toan, diem_ly, diem_hoa)
            students.append(student)
    return students


def export_data_to_file(students, file_name):
    with open(file_name, 'w') as file:
        for student in students:
            file.write("ID:{}\n".format(student.mssv))
            file.write("Full name:{}\n".format(student.name))
            file.write("City:{}\n".format(student.city))
            file.write("Diem Toan:{}\n".format(student.diem_toan))
            file.write("Diem Ly:{}\n".format(student.diem_ly))
            file.write("Diem Hoa:{}\n".format(student.diem_hoa))
            file.write("Average Score:{}\n".format(student.calculate_average_score()))
            file.write("------------------------\n")


if __name__ == "__main__":
    # Đọc dữ liệu từ file student.txt
    file_name = 'student.txt'
    students = read_data_from_file(file_name)

    # Hiển thị thông tin sinh viên
    for student in students:
        student.display_info()

    # Xuất dữ liệu ra file scan.txt
    export_data_to_file(students, 'scan.txt')
