import tkinter as tk

from tkinter import messagebox as msg

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('Demo')
        lbl_demo = tk.Label(self, text = 'Khoa Công Nghệ Thông Tin\n Chào mừng các Tân sinh viên khóa 2022', 
        relief = tk.SUNKEN, border = 1, font = ('Calibri', 15), background = 'aqua')
        btn_exit = tk.Button(self, text = 'Exit', width = 7, font = ('Calibri', 13), command = self.btn_exit_click)
        
        lbl_demo.grid(row = 0, column = 0, padx = 10, pady = 10, ipadx = 10, ipady = 10)
        btn_exit.grid(row = 1, column = 0, padx = 10, pady = 10)

        self.protocol("WM_DELETE_WINDOW", self.btn_exit_click)
           
    def btn_exit_click(self):
        answer = msg.askquestion('Warning', 'Bạn có muốn thoát không?')
        if answer == 'yes':
            self.destroy()


if __name__ == "__main__":
    app = App()
    app.mainloop()