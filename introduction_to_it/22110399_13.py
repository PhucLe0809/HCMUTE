import tkinter as tk
import tkinter.filedialog as fd
from tkinter import ttk

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 13')
        self.geometry("660x480")
        self.resizable(False, False)
        style = ttk.Style()
        style.theme_use('classic')
        style.configure("Vertical.TScrollbar", background = 'pink', bordercolor = 'yellow', arrowcolor = 'white')
        btn_open = tk.Button(self, text = 'Open Text File',width = 10, command = self.btn_open_click)
        btn_scan = tk.Button(self, text = 'Scan', width = 10, command = self.btn_scan_click)
     
        self.lst_list = tk.Text(self, relief = tk.SUNKEN, bg = 'white', width = 27, height = 19, font = ('Arial', 14), wrap = tk.WORD)
        self.lst_attendance = tk.Text(self, relief = tk.SUNKEN, bg = 'white', width = 42, height = 26, font = ('Arial', 10), wrap = tk.WORD)
        self.scroll_y = ttk.Scrollbar(self, orient = tk.VERTICAL, command = self.lst_list.yview)
        btn_open.place(x = 10, y = 10)
        btn_scan.place(x = 400, y = 10)
        self.lst_list.place(x = 10, y = 40)
        self.lst_attendance.place(x = 340, y = 40)
    def btn_open_click(self):
        filetypes = (
        ('text files', '*.txt'),
        ('All files', '*.*')
        )
        filename = fd.askopenfilename(title="Open file",initialdir="/", filetypes=filetypes)
        f = open("%s" %filename, 'r', encoding = 'utf-8')
        self.content = f.read()
        f.close()
        self.lst_list.insert(tk.INSERT, self.content)
        self.lst_list.configure(yscrollcommand = self.scroll_y.set)
        self.scroll_y.place(x = 310, y = 40, height = 422)
        
    def btn_scan_click(self):
        i = 0
        noidung = ''
        t = ''
        while(i < len(self.content)):
            if(self.content[i] >= 'A' and self.content[i] <= 'Z' and self.content[i-1] == '\n'):
                j = i
                while(self.content[j] != ':'):
                    t = t + self.content[j]
                    j = j + 1
                noidung = noidung + t + '\n'
                i = j
                t = ''
            else:
                i = i + 1
        self.lst_attendance.insert(tk.INSERT, noidung)
        f = open('DanhSach.txt', 'w')
        f.write(noidung)
        f.close()

if __name__ == "__main__":
    app = App()
    app.mainloop()