n = int(input())
student = {
    'id' : '',
    'name' : '',
    'age' : '',
    'city' : ''
}
inp = []

for i in range(0, n):
    for key in student:
        student[key] = input()
    # print(student, sep = '\n', end = '\n')
    inp.append(student)

for x in inp:
    print(x, sep = '\n', end = '\n')
print()
for x in inp:
    if (int(x['age']) > 20):
        print(x, sep = '\n', end = '\n')
print()
for x in inp:
    if (x['city'] == 'ha noi'):
        print(x, sep = '\n', end = '\n')
