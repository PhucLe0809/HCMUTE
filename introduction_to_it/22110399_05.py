import tkinter as tk
import tkcalendar
from tkinter import messagebox as msg

class App(tk.Tk):
    def __init__(self):

        super().__init__()

        self.title('EXERCISE 05')
        self.geometry('525x480')
        #self.resizable(False, False)
        lbl_full_name = tk.Label(self, text  = 'Full name' )
        lbl_day_of_birth = tk.Label(self, text = 'Day of birth')
        lbl_female = tk.Label(self, text = 'Female')
        lbl_scores = tk.Label(self, text = 'Scores')
        lbl_list = tk.Label(self, text = 'List')
        self.lbl_amount = tk.Label(self, text = 'Amount')
        self.lbl_result_count = tk.Label(self, relief = tk.SUNKEN, width = 5, justify = tk.CENTER)
        self.lbl_medium_score = tk.Label(self, text = 'Medium score')
        self.lbl_result_score = tk.Label(self, relief = tk.SUNKEN, justify = tk.CENTER, width = 5)

        self.btn_add = tk.Button(self, text = 'Add', width = 10, command = self.btn_add_click)
        self.full_name = tk.StringVar()
        self.ent_full_name = tk.Entry(self, width = 30, textvariable = self.full_name)
        self.day_of_birth = tk.StringVar()
        self.ent_day_of_birth = tkcalendar.DateEntry(self, date_pattern = 'dd/mm/yyyy'
        , day = 1, month = 1, year = 2003, textvariable = self.day_of_birth)
        
        self.score_so = tk.StringVar()
        self.ent_score_so = tk.Entry(self, width = 6, textvariable = self.score_so)
        
        self.female = tk.IntVar()
        self.chk_female = tk.Checkbutton(self, anchor = tk.W, variable = self.female)

        a = 8
        lbl_full_name.grid(row = 0, column = 0, padx = a , pady = 10, sticky = tk.W)
        lbl_day_of_birth.grid(row = 1, column = 0, padx = a , pady = 10, sticky = tk.W)
        lbl_female.grid(row = 2, column = 0, padx = a, pady = 10, sticky = tk.W)
        lbl_scores.grid(row = 3, column = 0, padx = a, pady = 10, sticky = tk.W)
        lbl_list.grid(row = 4, column = 0, padx = a,pady = 3, sticky = tk.SW)
        self.lbl_amount.grid(row = 6, column = 0 ,padx = 10, pady = 10, sticky = tk.W)
        self.lbl_result_count.grid(row = 6, column = 1, padx = 10, pady = 10, sticky = tk.W)
        self.lbl_medium_score.grid(row = 7, column = 0, padx = 10, pady = 10, sticky = tk.W)
        self.lbl_result_score.grid(row = 7, column = 1, padx = 10, pady = 10, sticky = tk.W)

        self.ent_full_name.grid(row = 0, column = 1, pady = 15, sticky = tk.W)
        self.ent_day_of_birth.grid(row = 1, column = 1, pady = 0, sticky = tk.W)
        self.ent_score_so.grid(row = 3, column = 1,pady = 10, sticky = tk.W)
        self.chk_female.grid(row = 2, column = 1,padx = 0, pady = 10, sticky = tk.W)
        self.btn_add.grid(row = 0, column = 5, padx = 10, pady = 10)
        
        self.lst_list = tk.Listbox(self, relief = tk.SUNKEN, width = 53, font = ('Courier New', 11),activestyle = tk.NONE)
        self.lst_list.grid(row = 5, padx = 10,columnspan = 6, sticky = tk.W)
        self.ent_full_name.focus_set()

        self.amount = 0
        self.tong_score = 0
        self.score_tb = 0
    def btn_add_click(self):
        full_name = self.full_name.get().strip()
        if full_name == "":
            return
        full_name = full_name.split()
        last_name = full_name[-1]
        first_name = ''
        for x in full_name[:-1]:
            first_name = first_name + x + ' '
        first_name = first_name.strip()
        first_name = first_name + ' '*(20 - len(first_name))
        last_name = last_name + ' '*(10 - len(last_name))
        full_name = first_name + last_name
        day_of_birth = self.day_of_birth.get()
        female = 'Male '
        if self.female.get() == 1:
            female = 'Female '
        score = self.score_so.get().strip()
        if score == "":
            return
        score = float(score)
        score = '%4.1f' % score
        
        self.content = first_name + last_name + day_of_birth + '  ' + female  +  score
        self.amount += 1
        self.tong_score += float(score)
        self.score_tb = float(self.tong_score / self.amount)
        self.lbl_result_count.configure(text = '%d' % self.amount)
        self.lbl_result_score.configure(text = '%.2f' % self.score_tb)
        self.lst_list.insert(tk.END, self.content)
        self.ent_full_name.delete(0, tk.END)
        self.ent_day_of_birth.set_date('01/01/2004')
        self.ent_score_so.delete(0, tk.END)
        self.chk_female.deselect()
        self.ent_full_name.focus_set()

if __name__ == "__main__":
    app = App()
    app.mainloop()