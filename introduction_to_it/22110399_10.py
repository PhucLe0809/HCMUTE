import tkinter as tk
from tkinter import messagebox as msg
import numpy as np

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 10')
        self.geometry("640x480")
        self.radius = tk.StringVar()
        lbl_enter = tk.Label(self, text = 'Enter Radius')
        ent_enter_radius = tk.Entry(self, textvariable = self.radius)
        btn_enter = tk.Button(self, text = 'Enter', width = 10, command = self.btn_enter_click)

        lbl_enter.place(x = 200, y = 200)
        ent_enter_radius.place(x = 300, y = 200)
        btn_enter.place(x = 300, y = 230)

    def btn_enter_click(self):
        new_window = tk.Toplevel()
        new_window.title("Draw Circle")
        new_window.geometry("640x480")
        new_window.resizable(False, False)
        cvs_draw = tk.Canvas(new_window, width = 620, height = 460, relief = tk.SUNKEN, bg = 'white')
        R = self.radius.get()
        R = float(R)
        cvs_draw.place(x = 10, y = 10)
        cvs_draw.create_oval(310 - R, 230 - R, 310 + R, 230 + R, fill = 'pink', outline = 'salmon')

if __name__ == "__main__":
    app = App()
    app.mainloop()