import tkinter as tk
from tkinter import messagebox as msg
import numpy as np

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 11')
        self.geometry("600x600")
        self.radius = tk.StringVar()
        btn_enter_radius = tk.Button(self, text = 'Enter Radius', width = 15, command = self.btn_enter_radius_click)
        btn_enter_radius.place(x = 250, y = 550)
        
    def btn_enter_radius_click(self):
        self.new_window = tk.Toplevel()
        self.new_window.title("Enter Radius")
        self.new_window.geometry("200x200")
        self.new_window.resizable(False, False)
        lbl_enter = tk.Label(self.new_window, text = "Enter Radius")
        self.ent_enter = tk.Entry(self.new_window, textvariable = self.radius)
        btn_enter = tk.Button(self.new_window, text = 'OK', width = 15, command = self.btn_enter_click)

        lbl_enter.place(x = 50, y = 40)
        self.ent_enter.place(x = 40, y = 70)
        btn_enter.place(x = 40, y = 120)
        self.ent_enter.delete(0, tk.END)

    def btn_enter_click(self):
        self.new_window.destroy()
        R = self.radius.get()
        R = float(R)
        cvs_draw = tk.Canvas(self, width = 800, height = 800, relief = tk.SUNKEN, bg = 'white')
        cvs_draw.place(x = 0, y = 0)
        cvs_draw.create_oval(300 - R, 300 - R, 300 + R, 300 + R, fill = 'pink', outline = 'salmon')
        btn_enter_radius = tk.Button(self, text = 'Enter Radius', width = 15, command = self.btn_enter_radius_click)
        btn_enter_radius.place(x = 250, y = 550)
        
if __name__ == "__main__":
    app = App()
    app.mainloop()