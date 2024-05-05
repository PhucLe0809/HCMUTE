import tkinter as tk
import math

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 07')
        self.cvs_figure = tk.Canvas(self, width = 300, height = 300, relief = tk.SUNKEN, border = 1)
        self.cvs_figure.grid(row = 0, column = 0, padx = 5, pady = 5)

        lblf_picture = tk.LabelFrame(self)
        btn_sin = tk.Button(lblf_picture, text = 'Sin', width = 7, command = self.btn_sin_click)
        btn_parabol = tk.Button(lblf_picture, text = 'Parabol', width = 7, command = self.btn_parabol_click)
        btn_circle = tk.Button(lblf_picture, text = 'Circle', width = 7, command = self.btn_circle_click)
        btn_rose = tk.Button(lblf_picture, text = 'Rose', width = 7, command = self.btn_rose_click)

        btn_sin.grid(row = 0, column = 0, padx = 5, pady = 5)
        btn_parabol.grid(row = 1, column = 0, padx = 5, pady = 5)
        btn_circle.grid(row = 2, column = 0, padx = 5, pady = 5)
        btn_rose.grid(row = 3, column = 0, padx = 5, pady = 5)

        lblf_picture.grid(row = 0, column = 1, padx = 5, pady = 7, sticky = tk.N)

    def btn_sin_click(self):
        self.cvs_figure.delete('all')
        W = 301
        H = 289
        N = 50
        dx = 2*math.pi/N
        pixel = []
        for i in range(0, N+1):
            x = i*dx
            y = math.sin(x)
            m = W*x/(2*math.pi)
            n = H*(1-y)/2 
            pixel.append(m)
            pixel.append(n+6)
        self.cvs_figure.create_line(pixel)

    def btn_parabol_click(self):
        self.cvs_figure.delete('all')
        W = 300
        H = 300
        scale = H/8
        N = 50
        dx = 4/N
        pixel = []
        xc = W // 2
        yc = H // 2 
        for i in range(-N // 2, N // 2 + 1):
            x = i*dx
            y = x**2
            m = x*scale
            n = y*scale
            pixel.append(xc + m) 
            pixel.append(yc - n)
        self.cvs_figure.create_line(pixel)

    def btn_circle_click(self):
        self.cvs_figure.delete('all')
        W = 300
        H = 300
        r = 100
        N = 50
        dtheta = 2*math.pi/N
        xc = W // 2
        yc = H // 2
        pixel = []
        for i in range(0, N+1):
            theta = i*dtheta
            x = r*math.cos(theta)
            y = r*math.sin(theta)
            pixel.append(xc + x)
            pixel.append(yc + y)
        self.cvs_figure.create_line(pixel)

    def btn_rose_click(self):
        self.cvs_figure.delete('all')
        W = 300
        H = 300
        N = 100
        dtheta = 3*2*math.pi/N
        xc = W // 2
        yc = H // 2
        n = 4
        d = 3
        k = n/d
        a = 100
        pixel = []
        for i in range(0, N+1):
            theta = i*dtheta
            r = a*math.cos(k*theta)
            x = r*math.cos(theta)
            y = r*math.sin(theta)
            pixel.append(xc + x)
            pixel.append(yc + y)
        self.cvs_figure.create_line(pixel)



if __name__ == "__main__":
    app = App()
    app.mainloop()

