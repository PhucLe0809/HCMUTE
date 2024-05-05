import tkinter as tk
import tkinter.filedialog as fd
from PIL import Image, ImageTk
from tkinter.constants import BOTH, BOTTOM, LEFT, NONE, RIGHT, SUNKEN, TOP, X, Y, YES

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 08')
        self.geometry("625x438")
        menu = tk.Menu(self)
        file_menu = tk.Menu(menu, tearoff = 0)

        file_menu.add_command(label = "Open Image", command = self.btn_open_click)
        file_menu.add_command(label = "Clear Image", command = self.btn_clear_click)
        file_menu.add_separator()
        file_menu.add_command(label = "Exit", command = self.btn_exit_click)
        
        menu.add_cascade(label = "File", menu = file_menu)
        self.config(menu=menu)

        self.cvs_figure = tk.Canvas(self, relief = tk.SUNKEN, bg ='white')
        self.lbl_file_name = tk.Label(self, text = 'Filename', anchor = tk.W)
        self.lbl_size_image = tk.Label(self, text = 'WxH', bg = 'white', relief = tk.SUNKEN)
        self.cvs_figure.pack(fill=BOTH, expand=YES, padx=2, pady=1)
        self.lbl_file_name.pack(side=LEFT)
        self.lbl_size_image.pack(side=RIGHT)
    
    def btn_exit_click(self):
        self.destroy()

    def btn_open_click(self):
        filetypes = (("Images", "*.jpg *.gif *.png"),)
        self.filename = fd.askopenfilename(title="Open file",initialdir="/", filetypes=filetypes)
        
        pilImage = Image.open("%s" %self.filename)
        self.image = ImageTk.PhotoImage(pilImage)
        W1 = self.winfo_width()
        H1 = self.winfo_height()
        pilImage = pilImage.resize((W1, H1), Image.ANTIALIAS)  

        self.image = ImageTk.PhotoImage(pilImage)
        self.cvs_figure.create_image(0, 0,anchor = tk.NW, image=self.image)
        self.lbl_file_name.configure(text = '%s' %self.filename)
        self.lbl_size_image.configure(text ='%dx%d' %(W1,H1))
        self.cvs_figure.bind('<Configure>', self.resize)
    def resize(self, event):
        self.cvs_figure.delete("all")
        W, H = event.width, event.height
        
        pillowImage = Image.open("%s" %self.filename)
        self.image = ImageTk.PhotoImage(pillowImage)
        pillowImage = pillowImage.resize((W, H), Image.ANTIALIAS)

        self.image = ImageTk.PhotoImage(pillowImage)
        self.cvs_figure.create_image(0, 0, anchor = tk.NW, image=self.image)
        self.lbl_file_name.configure(text = '%s' %self.filename)
        self.lbl_size_image.configure(text ='%dx%d' %(W, H))
        
    def btn_clear_click(self):
        self.cvs_figure.delete('all')
        self.lbl_file_name.configure(text = 'Filename')
        self.lbl_size_image.configure(text = 'WxH')

if __name__ == "__main__":
    app = App()
    app.mainloop()