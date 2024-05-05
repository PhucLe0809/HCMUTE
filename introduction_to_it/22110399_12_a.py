import tkinter as tk
from tkinter import *

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 12 A')
        self.geometry('480x360')
        self.configure(bg = 'gainsboro')
        self.cvs_oval = tk.Canvas(self, bg = 'gainsboro',  relief = tk.SUNKEN,bd = 1,)
        self.cvs_oval.pack(fill=BOTH, expand=YES)
        self.cvs_oval.update()
        W = self.cvs_oval.winfo_width() - 2
        H = self.cvs_oval.winfo_height() - 2
        self.cvs_oval.create_oval(5, 5, W-5, H-5, fill='dodgerblue', outline='dodgerblue')

        self.cvs_oval.bind('<Configure>', self.resize)

    def resize(self, event):
        self.cvs_oval.delete("all")
        W, H = event.width, event.height
        self.cvs_oval.create_oval(5, 5, W-5, H-5, fill='dodgerblue', outline='dodgerblue')
     
if __name__ == "__main__":
    app = App()
    app.mainloop()