import tkinter as tk
import tkinter.filedialog as fd
from PIL import Image, ImageTk
from tkinter import ttk

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 08')
        self.geometry("500x350")
        self.resizable(False ,False)
        self.style = ttk.Style()
        self.style.theme_use('classic')
        self.style.configure("Vertical.TScrollbar", background="bisque", bordercolor="red", arrowcolor="white")
        self.style.configure("Horizontal.TScrollbar", background="bisque", bordercolor="red", arrowcolor="white")
        menu = tk.Menu(self)
        file_menu = tk.Menu(menu, tearoff = 0)

        file_menu.add_command(label = "Open Image", command = self.btn_open_click)
        file_menu.add_command(label = "Clear Image", command = self.btn_clear_click)
        file_menu.add_separator()
        file_menu.add_command(label = "Exit", command = self.btn_exit_click)
        
        menu.add_cascade(label = "File", menu = file_menu)
        self.config(menu=menu)

        self.cvs_figure = tk.Canvas(self,width = 480, height = 330, relief = tk.SUNKEN, bg ='white')
        self.cvs_figure.grid(row = 0, column = 0, sticky = tk.NSEW)
    def btn_exit_click(self):
        self.destroy()

    def btn_open_click(self):
        self.scroll_x = ttk.Scrollbar(self, orient = tk.HORIZONTAL)
        self.scroll_y = ttk.Scrollbar(self, orient = tk.VERTICAL)
        
        self.frame = tk.Frame(self.cvs_figure)
        self.cvs_figure.create_window((0, 0), window=self.frame,
                                        anchor=tk.NW)

        self.cvs_figure.config(xscrollcommand=self.scroll_x.set, yscrollcommand=self.scroll_y.set)
        self.scroll_x.config(command = self.cvs_figure.xview)
        self.scroll_y.config(command = self.cvs_figure.yview)
      
        filetypes = (("Images", "*.jpg *.gif *.png"),)
        filename = fd.askopenfilename(title="Open file",initialdir="/", filetypes=filetypes)
        pilImage = Image.open("%s" %filename)
        
        self.scroll_x.grid(row = 1, column = 0, sticky = tk.EW)
        self.scroll_y.grid(row = 0, column = 1, sticky = tk.NS)

        self.image = ImageTk.PhotoImage(pilImage)
        self.cvs_figure.create_image(0, 0,anchor = tk.NW, image=self.image)
        self.bind("<Configure>", self.resize)
        self.update_idletasks()
        
    
    def btn_clear_click(self):
        self.cvs_figure.delete('all')
        self.scroll_x.destroy()
        self.scroll_y.destroy()

    def resize(self, event):
        region = self.cvs_figure.bbox(tk.ALL)
        self.cvs_figure.configure(scrollregion=region)

if __name__ == "__main__":
    app = App()
    app.mainloop()