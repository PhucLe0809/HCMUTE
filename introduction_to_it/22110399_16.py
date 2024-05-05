from multiprocessing.sharedctypes import Value
import tkinter as tk
import numpy as np

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 16')
        self.geometry('600x600')

        self.scale = tk.Scale(self, from_=1, to=30, orient=tk.HORIZONTAL, length=575, resolution=1, command=self.Value)
        self.scale.place(x=10, y=10)

        self.scale.set(value=1)
        
        self.cvs_figure = tk.Canvas(self,  width=576, height=512,bg='oldlace')
        self.cvs_figure.place(x=10, y=75)
        self.cvs_figure.update()
        W = (self.cvs_figure.winfo_width()-8)/30*2
        H = self.cvs_figure.winfo_height()-8
        n = 10000
        dx = 30*2*np.pi/n
        data = []
        for i in range (0, n+1):
            x = i*dx
            y = np.sin(x)
            p = W*x/(2*2*np.pi)
            q = (H/30)*(30-y)/2+4
            data.append(p)
            data.append(q)
        self.cvs_figure.create_line(data, fill='orangered')
        self.scale.bind('<Configure>', self.resize)

    def Value(self, value):
        self.value = float(value)
        self.resize()

    def resize(self):
        self.cvs_figure.delete('all')
        self.cvs_figure.update()
        CK = 31-self.value
        w = (self.cvs_figure.winfo_width()-8)/CK*2
        H = self.cvs_figure.winfo_height()-8
        n = 10000
        dx = CK*2*np.pi/n
        data = []
        for i in range (0, n+1):
            x = i*dx
            y = np.sin(x)
            p = w*x/(2*2*np.pi)
            q = (H/CK)*(CK-y)/2 + 4
            data.append(p)
            data.append(q)
        self.cvs_figure.create_line(data, fill='orangered')

if __name__ == "__main__":
    app = App()
    app.mainloop()
