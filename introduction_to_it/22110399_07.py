import tkinter as tk
from tkinter import messagebox as msg
import numpy as np

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 07')
        self.geometry("640x480")
        self.cvs_figure = tk.Canvas(self, width = 400, height = 400, bg = 'white'
                                    ,relief = tk.SUNKEN, bd = 1)
        btn_start = tk.Button(self, text = 'Start', width = 10, command = self.btn_start_click)
        btn_stop = tk.Button(self, text = 'Stop', width = 10, command = self.btn_stop_click)

        self.cvs_figure.place(x = 10, y = 10)
        btn_start.place(x = 480, y = 10)
        btn_stop.place(x = 480, y = 50)

        self.cvs_figure.update()
        W = self.cvs_figure.winfo_width() - 1
        H = self.cvs_figure.winfo_height() - 1
        R = W / 2 - 10
        xc = W / 2
        yc = H / 2
        self.cvs_figure.create_oval(10, 10, W - 10, H - 10, fill = 'white', outline = 'blue' )
        self.cvs_figure.create_rectangle(xc+R-5,yc-5,xc+R+5,yc+5, fill = 'red')   
        self.j = 1
        self.bamstart = 0
        self.vitri = 0
    def btn_stop_click(self):
        self.j = 2
    def btn_start_click(self):
        self.j = 1
        self.bamstart = self.bamstart + 1
        if self.bamstart == 1:
            self.cvs_figure.update()
            W = self.cvs_figure.winfo_width() - 1
            H = self.cvs_figure.winfo_height() - 1
            n = 10000
            R = W / 2 - 10
            xc = W / 2
            yc = H / 2
            delta = 2*np.pi/n
            temp = self.vitri
            while self.j < 2:
                theta = (temp % (n+1)) * delta
                x = R * np.cos(theta)
                y = R * np.sin(theta)
                self.cvs_figure.update()
                self.cvs_figure.delete('all')
                self.cvs_figure.create_oval(10, 10, W - 10, H - 10, fill = 'white', outline = 'blue')
                self.cvs_figure.create_rectangle(xc+x-5,yc-y-5,xc+x+5,yc-y+5, fill = 'red')
                temp = temp + 1
                self.vitri = temp
            if(self.j == 2):
                self.bamstart = 0
    
if __name__ == "__main__":
    app = App()
    app.mainloop()