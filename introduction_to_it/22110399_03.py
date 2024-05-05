import tkinter as tk

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 03')
        self.geometry('385x325')
        self.resizable(False, False)
        #Canvas
        self.cvs_picture = tk.Canvas(self, relief = tk.SUNKEN, border = 1, width = 250, height = 300)
        self.picture = tk.StringVar()
        #Label Frame
        lblf_picture = tk.LabelFrame(self, text = 'Picture')
        #Radio Button
        rbtn_elip = tk.Radiobutton(lblf_picture, text = 'Elip', value = 'Elip', variable = self.picture, command = self.scan)
        rbtn_rectangle = tk.Radiobutton(lblf_picture, text = 'Rectangle', value = 'Rectangle', variable = self.picture, command = self.scan)
        rbtn_triangle = tk.Radiobutton(lblf_picture, text = 'Triangle', value = 'Triangle', variable = self.picture, command = self.scan)

        self.picture.set('Elip')
        #Integer Variable
        self.red = tk.IntVar()
        self.green = tk.IntVar()
        self.blue = tk.IntVar()
        #Color
        lblf_color = tk.LabelFrame(self, text = 'Color')
        chk_red = tk.Checkbutton(lblf_color, text = 'Red', variable = self.red, command = self.scan)
        chk_green = tk.Checkbutton(lblf_color, text = 'Green', variable = self.green, command = self.scan)
        chk_blue = tk.Checkbutton(lblf_color, text = 'Blue', variable = self.blue, command = self.scan)
        self.red.set(1)
        #Place
        self.cvs_picture.place(x = 10, y = 10)
        #Đẩy Radio Button ra Window
        rbtn_elip.grid(row = 0, padx = 5, pady = 5, sticky = tk.W)
        rbtn_rectangle.grid(row = 1, padx = 5, pady = 5, sticky = tk.W)
        rbtn_triangle.grid(row = 2, padx = 5, pady = 5, sticky = tk.W)
        #Color in Window
        chk_red.grid(row = 0, padx = 5, pady = 5, sticky = tk.W)
        chk_green.grid(row = 1, padx = 5, pady = 5, sticky = tk.W)
        chk_blue.grid(row = 2, padx = 5, pady = 5, sticky = tk.W)
        #Label Frame 
        lblf_picture.place(x = 275, y = 5, width = 100)
        lblf_color.place(x = 275, y = 191, width = 100)

        p = [10, 10, 245, 295]
        self.cvs_picture.create_oval(p, fill = 'Red', outline = 'Red')
        self.cvs_picture.update()

    def scan(self):
        self.cvs_picture.delete('all')
        color = '#'
        if self.red.get() == 1:
            color = color + 'FF'
        else:
            color = color + '00'
        if self.green.get() == 1:
            color = color + 'FF'
        else:
            color = color + '00'
        if self.blue.get() == 1:
            color = color + 'FF'
        else:
            color = color + '00'
        if self.picture.get() == 'Elip':
            p = [10, 10, 245, 295]
            self.cvs_picture.create_oval(p, fill = color, outline = color)
        elif self.picture.get() == 'Rectangle':
            p = [10, 10, 245, 295]
            self.cvs_picture.create_rectangle(p, fill = color, outline = color)
        else:
            p = [10, 295, 10 + (245-10) // 2 , 10, 245, 295]
            self.cvs_picture.create_polygon(p, fill = color, outline = color)

if __name__ == "__main__":
    app = App()
    app.mainloop()
