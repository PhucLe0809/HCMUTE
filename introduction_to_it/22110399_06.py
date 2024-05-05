import tkinter as tk
from tkinter import messagebox as msg

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('EXERCISE 06')
        self.geometry('450x300')
        self.resizable(False, False)
        lbl_fruit = tk.Label(self, text = 'Fruit', relief = tk.SUNKEN, width = 7)
        
        self.menu = tk.Menu(self, tearoff=0)
        self.menu.add_command(label="Select All", command=self.select_all_click)
        self.menu.add_command(label="Copy To Right", command=self.copy_text)
        self.menu.add_command(label="Move To Right", command=self.move_text)
        self.menu.add_command(label="Delete", command=self.delete_selected)
        self.amount_main = 0
        self.amount_temp = 0
        
        self.fruit = tk.StringVar()
        self.ent_fruit = tk.Entry(self, textvariable = self.fruit)
        
        btn_cin = tk.Button(self, text = 'Add',width = 10, command = self.btn_cin_click)
        self.lst_fruit_main = tk.Listbox(self,  width = 25, activestyle = tk.NONE,
        selectmode = tk.EXTENDED )
        self.lst_fruit_temp = tk.Listbox(self,  width = 25)
        lbl_amount = tk.Label(self, text = 'Amount', relief = tk.SUNKEN, width = 9,
        anchor = tk.CENTER)
        self.lbl_count_slmain = tk.Label(self, relief = tk.SUNKEN, width = 2)
        lbl_amount_temp = tk.Label(self, text = 'Amount', relief = tk.SUNKEN, width = 9 )
        self.lbl_count_sltemp = tk.Label(self, relief = tk.SUNKEN, width = 2)

        lbl_fruit.place(x = 10, y = 10)
        self.ent_fruit.place(x = 90, y = 10)
        btn_cin.place(x = 270, y = 9, height = 20)
        self.lst_fruit_main.place(x = 10, y = 50)
        self.lst_fruit_temp.place(x = 230, y = 50)
        lbl_amount.place(x = 10, y = 234)
        self.lbl_count_slmain.place(x = 85, y = 234)
        lbl_amount_temp.place(x = 230, y = 234)
        self.lbl_count_sltemp.place(x = 304, y = 234)
        self.ent_fruit.focus_set()

        self.lst_fruit_main.bind("<Button-3>", self.show_popup)
    def show_popup(self, event):
        self.menu.post(event.x_root, event.y_root)
    def select_all_click(self):
        self.lst_fruit_main.select_set(0, tk.END)
    def delete_selected(self):
        count = 0
        for i in self.lst_fruit_main.curselection()[::-1]:
            self.lst_fruit_main.delete(i)
            count += 1
        self.lbl_count_slmain.configure(text = '%d' % (self.amount_main - count))

    def copy_text(self):
        for i in self.lst_fruit_main.curselection()[::-1]:
            fruit = self.lst_fruit_main.get(i)
            self.lst_fruit_temp.insert(0, fruit)
            self.amount_temp += 1
        self.lbl_count_sltemp.configure(text = '%d' % self.amount_temp)
    
    def move_text(self):
        for i in self.lst_fruit_main.curselection()[::-1]:
            fruit = self.lst_fruit_main.get(i)
            self.lst_fruit_main.delete(i)
            self.lst_fruit_temp.insert(0, fruit)
            self.amount_temp += 1
            self.amount_main -= 1
        self.lbl_count_sltemp.configure(text = '%d' % self.amount_temp)
        self.lbl_count_slmain.configure(text = '%d' % (self.amount_main))
    
    def btn_cin_click(self):
        fruit = self.fruit.get()
        fruit = fruit.strip()
        if fruit == "":
            return
        self.amount_main += 1
        self.lst_fruit_main.insert(tk.END, fruit)
        self.lbl_count_slmain.configure(text = '%d' % (self.amount_main))
        self.ent_fruit.delete(0, tk.END)

if __name__ == "__main__":
    app = App()
    app.mainloop()