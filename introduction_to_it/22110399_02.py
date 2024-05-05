import math
import tkinter as tk
from tkinter import ttk
import tkinter.messagebox as mbox

from tkinter import messagebox as msg

class App(tk.Tk):
    def __init__ (self):
        super().__init__()
        self.title('Giải phương trình bậc 2')
        self.resizable(False, False)
        #win = tk.Tk()
        #Total Variable
        self.a = tk.StringVar()
        self.b = tk.StringVar()
        self.c = tk.StringVar()
        #Label
        lbl_name = tk.Label(self, text = 'Giải phương trình bậc 2\n Cấu trúc ax^2 + bx + c = 0', 
        relief = tk.SUNKEN, border = 1, font = ('Calibri', 15), background = 'aqua')
        lbl_cin_a = tk.Label(self, text = 'Nhập a', font = ('Calibri', 15))
        lbl_cin_b = tk.Label(self, text = 'Nhập b', font = ('Calibri', 15))
        lbl_cin_c = tk.Label(self, text = 'Nhập c', font = ('Calibri', 15))
        lbl_cout = tk.Label(self, text = 'Nghiệm', font = ('Calibri', 15))
        lbl_space = tk.Label(self, text = '         ')
        self.lbl_answer = tk.Label(self, relief = tk.SUNKEN, border = 1, font = ('Calibri', 15))
        #Entry
        self.ent_cin_a = tk.Entry(self, justify = tk.RIGHT, font = ('Calibri', 15), textvariable = self.a)
        self.ent_cin_b = tk.Entry(self, justify = tk.RIGHT, font = ('Calibri', 15), textvariable = self.b)
        self.ent_cin_c = tk.Entry(self, justify = tk.RIGHT, font = ('Calibri', 15), textvariable = self.c)
        #self.ent_cout = tk.Entry(self, justify = tk.RIGHT, font = ('Calibri', 15))
        #Button
        btn_solution = tk.Button(self, text = 'Giải', width = 7, font = ('Calibri', 11), background = 'yellow', fg = 'red', 
        command = self.btn_solution_click) 
        btn_clean = tk.Button(self, text = 'Xóa', width = 7, font = ('Calibri', 11), background = 'lavender',
        command = self.btn_clean_click)
        btn_exit = tk.Button(self, text = 'Thoát', width = 7, font = ('Calibri', 11), background = 'lavender', fg = 'blue',
        command = self.btn_exit_click)
        #btn_show = tk.Button(self, text = 'Xem định dạng!', width = 15, font = ('Times New Roman', 12), background = 'lavender',
        #command = self.btn_show)
        #Solution
        a = self.ent_cin_a.get()
        b = self.ent_cin_b.get()
        c = self.ent_cin_c.get()
        #Đẩy Label ra window
        lbl_name.grid(row = 0, column = 0, padx = 10, pady = 10, ipadx = 10, ipady = 10, columnspan = 3)
        lbl_cin_a.grid(row = 1, column = 0, padx = 10,pady = 10)
        lbl_cin_b.grid(row = 2, column = 0, padx = 10, pady = 10)
        lbl_cin_c.grid(row = 3, column = 0, padx = 10, pady = 10)
        lbl_cout.grid(row = 4, column = 0, padx = 10, pady = 10)
        lbl_space.grid(row = 5, column = 0, padx = 10, pady = 10)
        self.lbl_answer.grid(row = 4, column = 1, padx = 10, pady = 10, sticky = tk.EW)
        #Đẩy Entry ra Window
        self.ent_cin_a.grid(row = 1, column = 1, padx = 10, pady = 10)
        self.ent_cin_b.grid(row = 2, column = 1, padx = 10, pady = 10)
        self.ent_cin_c.grid(row = 3, column = 1, padx = 10, pady = 10)
        #Đẩy Button ra window
        btn_solution.grid(row = 1, column = 2, padx = 10, pady = 10, sticky = tk.EW)
        btn_clean.grid(row = 2, column = 2, padx = 10, pady = 10, sticky = tk. EW)
        btn_exit.grid(row = 3, column = 2, padx = 10, pady = 10, sticky = tk.EW)
        #btn_show.grid(row = 5, column = 0, padx = 10, pady = 10, sticky = tk.EW)
        #Variable
        self.ent_cin_a.focus_set()
        #Button Exit Click
        self.protocol("WM_DELETE_WINDOW", self.btn_exit_click)
    def btn_exit_click(self):
        answer = msg.askquestion('Warning!', 'Bạn có muốn thoát chương trình không?')
        if answer == 'yes':
            self.destroy()
    # def btn_show():
    #     lbl_show = tk.Label(tk, text = 'Bạn đã nhập phương trình ' + self.ent_cin_a.get() + '^2 + ' + self.ent_cin_b.get() + 'x + ' 
    #      + self.ent_cin_c.get() + ' = 0', font = ('Calibri', 11))
    def btn_clean_click(self):
        self.lbl_answer.configure(text = '')
        self.ent_cin_a.delete(0, tk.END)
        self.ent_cin_b.delete(0, tk.END)
        self.ent_cin_c.delete(0, tk.END)
        self.ent_cin_a.focus_set()
    def btn_solution_click(self):
        a = self.a.get()
        b = self.b.get()
        c = self.c.get()
        try: 
            a = float(a)
        except:
            msg.showerror('Error', 'Bạn phải nhập a là 1 con số!')
            self.ent_cin_a.focus_set()
            return 
        try: 
            b = float(b)
        except:
            msg.showerror('Error', 'Bạn phải nhập b là 1 con số!')
            self.ent_cin_b.focus_set()
            return 
        try: 
            c = float(c)
        except:
            msg.showerror('Error', 'Bạn phải nhập c là 1 con số!')
            self.ent_cin_c.focus_set()
            return 
        a = float(a)
        b = float(b)
        c = float(c)
        delta = b**2 - 4*a*c
        if delta < 0:
            answer = 'PT vô nghiệm!'
        else:
            x1 = (-b + math.sqrt(delta))/(2*a)
            x2 = (-b - math.sqrt(delta))/(2*a)
            answer = 'x1 = %.2f, x2 = %.2f' % (x1, x2)
        self.lbl_answer.configure(text = answer)

if __name__ == "__main__":
    app = App()
    app.mainloop()
