import tkinter as tk
from tkinter import messagebox as msg
import numpy as np

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 04')
        self.geometry('425x285')
        self.matrix = None
        self.content = None
        btn_open = tk.Button(self, text ='Open', width = 10, command = self.btn_open_click)
        self.lbl_matrix = tk.Label(self, bg = 'white', relief = tk.SUNKEN,
                    width = 40, height = 10, anchor = tk.NW, justify = tk.LEFT,
                    font = ('Consolas' , 12))
               
        btn_plus = tk.Button(self, text = 'Plus', width = 10, command = self.btn_plus_click)
        btn_save = tk.Button(self, text = 'Save', width = 10, command = self.btn_save_click)
        btn_open.place(x = 10, y = 10)
        btn_save.place(x = 296, y = 250)
        self.lbl_matrix.place(x = 10, y = 45)
        btn_plus.place(x = 10, y = 250)

    def btn_open_click(self):
        file = open('matran.txt', 'r')
        content = file.read()
        file.close()
        content = content.splitlines()
        size = content[0]
        size = size.split()
        m = int(size[0])
        n = int(size[1])
        a = np.zeros((m , n), np.float)
        for i in range(0, m):
            line = content[i + 1]
            line = line.split()
            for j in range(0 , n):
                a[i , j] = float(line[j])

        self.matrix = a
        
        content = '%d %d\n' % (m , n)
        for i in range(0 , m):
            for j in range(0 , n):
                content = content +'%8.2f' % a[i,j]
            content = content + '\n'
        
        self.lbl_matrix.configure(text = content)

    def btn_plus_click(self):
        a = self.matrix
        m, n = a.shape
        content = '%d %d\n' % (m , n)
        for i in range(0 , m):
            for j in range(0 , n):
                content = content +'%8.2f' % a[i,j]
            content = content + '\n'
        content = content + '-'*32 + '\n'
        line = np.sum(a , axis = 0)
        for x in line:
            content = content + '%8.2f' % x
        content = content + '\n'
        self.content = content
        self.lbl_matrix.configure(text = content)

    def btn_save_click(self):
        file = open('ketqua.txt', 'w')
        file.write(self.content)
        file.close()
        msg.showinfo('Notification', 'You have finished recording')
        
if __name__ == "__main__":
    app = App()
    app.mainloop()