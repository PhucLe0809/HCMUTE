from tkinter import *
import tkinter as tk
from tkinter import CENTER, ttk
from turtle import bgcolor
import numpy as np

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 15')
        self.geometry('512x344')
        self.configure(bg = 'lightgoldenrodyellow')
        self.resizable(False, False)
        self.option_add('*Font', 'Times')

        self.cvs_figure = tk.Canvas(self, relief = tk.SUNKEN, bg = 'seashell', bd = 1, width = 485, height = 200)
        self.btn_open = tk.Button(self, text='Open Text File', command=self.open)
        self.btn_draw = tk.Button(self, text='Draw graphs bar', command=self.draw)

        self.btn_open.grid(row=0, column=0, padx=10, pady=10)
        self.btn_draw.grid(row=0, column=1, padx=10, pady=10)
        self.cvs_figure.grid(row=1, column=0, columnspan=2, padx=10)

    def open(self):
        f = open('DothiBar.txt', 'r')
        content = f.read()
        f.close()
        content = content.splitlines()

        heading = content[0]
        heading = heading.split()
        
        row1 = content[1]
        row1 = row1.split()

        row2 = content[2]
        row2 = row2.split()

        my_table = ttk.Treeview(self, height=2)

        my_table['columns'] = ('nam', 'qui1', 'qui2', 'qui3', 'qui4')

        my_table.column("#0", width=0,  stretch=NO)
        my_table.column("nam",anchor=CENTER, width=98)
        my_table.column("qui1",anchor=CENTER,width=98)
        my_table.column("qui2",anchor=CENTER,width=98)
        my_table.column("qui3",anchor=CENTER,width=98)
        my_table.column("qui4",anchor=CENTER,width=98)

        my_table.heading("nam",text=heading[0],anchor=CENTER)
        my_table.heading("qui1",text=heading[1],anchor=CENTER)
        my_table.heading("qui2",text=heading[2],anchor=CENTER)
        my_table.heading("qui3",text=heading[3],anchor=CENTER)
        my_table.heading("qui4",text=heading[4],anchor=CENTER)

        my_table.insert(parent='',index='end',iid=0,text='',
            values=(row1[0], row1[1], row1[2], row1[3], row1[4]))
        my_table.insert(parent='',index='end',iid=1,text='',
            values=(row2[0], row2[1], row2[2], row2[3], row2[4]))

        my_table.grid(row=2, column=0, columnspan=2, padx=10, pady=10)

    def draw(self):
        f = open('DothiBar.txt', 'r')
        content = f.read()
        f.close()
        content = content.splitlines()
        heading1 = content[1]
        heading1 = heading1.split()
        heading2 = content[2]
        heading2 = heading2.split()

        H = self.cvs_figure.winfo_height()

        row1 = content[1]
        row1 = row1.split()
        vitri1 = float(row1[1])
        vitri2 = float(row1[2])
        vitri3 = float(row1[3])
        vitri4 = float(row1[4])

        self.cvs_figure.create_rectangle(115, H-vitri1*10, 145, 200, fill='firebrick', outline='firebrick')
        self.cvs_figure.create_rectangle(213, H-vitri2*10, 243, 200, fill='firebrick', outline='firebrick')
        self.cvs_figure.create_rectangle(311, H-vitri3*10, 341, 200, fill='firebrick', outline='firebrick')
        self.cvs_figure.create_rectangle(409, H-vitri4*10, 439, 200, fill='firebrick', outline='firebrick')

        row2 = content[2]
        row2 = row2.split()
        vitri5 = float(row2[1])
        vitri6 = float(row2[2])
        vitri7 = float(row2[3])
        vitri8 = float(row2[4])

        self.cvs_figure.create_rectangle(146, H-vitri5*10, 176, 200, fill='dodgerblue', outline='dodgerblue')
        self.cvs_figure.create_rectangle(244, H-vitri6*10, 274, 200, fill='dodgerblue', outline='dodgerblue')
        self.cvs_figure.create_rectangle(342, H-vitri7*10, 372, 200, fill='dodgerblue', outline='dodgerblue')
        self.cvs_figure.create_rectangle(440, H-vitri8*10, 470, 200, fill='dodgerblue', outline='dodgerblue')

        self.cvs_figure.create_rectangle(10, 10, 40, 40, fill='firebrick', outline='firebrick')
        self.cvs_figure.create_rectangle(10, 50, 40, 80, fill='dodgerblue', outline='dodgerblue')
        self.cvs_figure.create_text(62, 25, text=heading1[0], font=('Helvetica 11 bold'))
        self.cvs_figure.create_text(62, 65, text=heading2[0], font=('Helvetica 11 bold'))

if __name__ == "__main__":
    app = App()
    app.mainloop()