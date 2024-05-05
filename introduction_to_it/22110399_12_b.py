import tkinter as tk
import tkinter.filedialog as fd
from tkinter import ttk
import os

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 12 B')
        self.geometry("625x480")
        self.resizable(False ,False)
        self.name_folder = tk.StringVar()
        lbl_enter = tk.Label(self, text = 'Enter Folder', relief = tk.SUNKEN)
        self.ent_enter = tk.Entry(self, width = 40, textvariable = self.name_folder)
        btn_enter = tk.Button(self, text = 'See', height = 1, width = 10, command = self.btn_enter_click)
        self.lst_subset = tk.Listbox(self, width = 100, font = ('Times New Roman' , 10), height = 26,
                                        activestyle = tk.NONE, relief = tk.SUNKEN)

        lbl_enter.place(x = 10, y = 10)
        self.ent_enter.place(x = 100, y = 10)   
        btn_enter.place(x = 400, y = 8)
        self.lst_subset.place(x = 10, y = 40)

    def btn_enter_click(self):
        self.lst_subset.delete(0, tk.END)
        src = self.name_folder.get()
        obj_list = os.listdir(src)
        length = len(obj_list)
        for i in range (0, length):
            content = src + '\\' + obj_list[i]
            self.lst_subset.insert(tk.END, content)

if __name__ == "__main__":
    app = App()
    app.mainloop()