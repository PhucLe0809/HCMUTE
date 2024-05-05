import tkinter as tk
import time

rong = 700
cao = 500
sizeM = 3
space = 50
len = 100
cc= 30
a = []
Mchu = []
chu = 'a'
delay= 0.5
value =1
cachLeTren = (100*space/50)*cc/30
check = True
def updataChu(x, i):
    global Mchu
    for j in range(sizeM,i,-1):
        Mchu.append('a')
        Mchu[j] = Mchu[j-1]
    if i==sizeM:
        Mchu.append('a')
    Mchu[i] = x
def ktao():
    global Mchu
    global sizeM
    global chu
    Mchu.clear()
    Background.delete("all")
    if sizeM <= 0:
        Mchu[0] = "NULL"
    else:
        Mchu.append('a')
        for i in range(1,sizeM):
            Mchu.append('a')
            Mchu[i]= chr(ord(Mchu[i-1])+1)
    chu = Mchu[sizeM-1]
    retangle(1,0,sizeM)
    pHeadTail(1)
    main.update()
    
def muiTenThang(x1,y1,x2,y2):
    Background.create_line(x1,y1,x2,y2,fill = "black",width= 3)
    main.update()
def Oh(hang):
    Background.create_text(space,cachLeTren*hang+cc/2-1,text = "o",font =10*len/100)
    Background.create_text(space,cachLeTren*hang-30, text = "pHead",font =10*len/100)
    main.update()
def pHead(hang):
    muiTenThang(space+3,cachLeTren*hang+cc/2,2*space,cachLeTren*hang+cc/2)
    Oh(hang)
    main.update()
def OT(hang):
    Background.create_text(len*(sizeM-1)+2*space+30+(len-100)/2,cachLeTren*hang-57,text = "o",font =10)
    Background.create_text(len*(sizeM-1)+2*space+70+(len-100)/2,cachLeTren*hang-57, text = "pTail",font =10)
    main.update()
def pTail(hang):
    global sizeM
    muiTenThang(len*(sizeM-1)+2*space+30-(100-len)/2,cachLeTren*hang,len*(sizeM-1)+2*space+30-(100-len)/2,cachLeTren*hang-50)
    OT(hang)
    main.update()
def retangle(hang,x,y):
    global Mchu
    j=0
    global chu
    for i in range(x,y):
        Background.create_rectangle(i*len+2*space,cachLeTren*hang,(i+1)*len+space,cachLeTren*hang+cc, fill = "white")
        Background.create_text(i * len+ 2*space+ len/4, cachLeTren*hang + cc / 2, text=Mchu[i], fill="black", font = 20)
    for i in range(x,y-1):
        muiTenThang((i+1)*len+space,cachLeTren*hang + cc / 2,(i+1)*len+2*space,cachLeTren*hang + cc / 2)
    main.update()
def pHeadTail(hang):
    pHead(hang)
    pTail(hang)
    main.update()
    
def oneRectangle(x1,y1,x2,y2,b,x):
    global Mchu
    global sizeM
    Background.create_rectangle(x1,y1,x2,y2,fill = b)
    Background.create_text((x1+x2)/2,(y1+y2)/2,text = x,font=20)
    main.update()
def themGiua(vt):
    global Mchu
    global sizeM
    global chu
    global check
    Background.delete("all")
    retangle(1,0,sizeM)
    pHeadTail(1)
    chu = chr(ord(chu)+1)
    oneRectangle((vt-1)*len+2*space,cachLeTren+2*space,vt*len+space,cachLeTren+2*space+cc,"white",chu)
    time.sleep(0.6)
    # tạo đường thẳng nối phần tử thêm vào với phần tử có vị trí cần chèn trong list hiện tại
    muiTenThang((vt-1)*len+2*space+(len-space)/2,cachLeTren+2*space,(vt-1)*len+2*space+(len-space)/2,cachLeTren+cc)
    time.sleep(0.6)
    # tạo đường thẳng nối giữ phần tử trước vị trí cần thêm với phần tử thêm vào
    muiTenThang((vt-1)*len+space-cc/2,cachLeTren+cc,(vt-1)*len+2*space,cachLeTren*2+cc/2)
    time.sleep(0.6)
    Background.delete("all")
    retangle(1,0,vt-1)
    retangle(1,vt-1,sizeM)
    pHeadTail(1)
    oneRectangle((vt-1)*len+2*space,cachLeTren+2*space,vt*len+space,cachLeTren+2*space+cc,"white",chu)
    # tạo đường thẳng nối phần tử thêm vào với phần tử có vị trí cần chèn trong list hiện tại
    muiTenThang((vt-1)*len+2*space+(len-space)/2,cachLeTren+2*space,(vt-1)*len+2*space+(len-space)/2,cachLeTren+cc)
    # tạo đường thẳng nối giữ phần tử trước vị trí cần thêm với phần tử thêm vào
    muiTenThang((vt-1)*len+space-cc/2,cachLeTren+cc,(vt-1)*len+2*space,cachLeTren*2+cc/2)
    
    updataChu(chu,vt-1)
    sizeM+=1
    retangle(3,0,sizeM)
    pHeadTail(3)
    check = False
    main.update()
    
def themCuoi():
    global check
    global Mchu
    global sizeM
    global chu
    Background.delete("all")
    retangle(1,0,sizeM)
    pHeadTail(1)
    chu = chr(ord(chu)+1)
    #thêm chữ cái tiếp theo vào Mchu
    updataChu(chu,sizeM)
    time.sleep(delay)
    #tạo phần tử thêm vào ở cuối
    retangle(1,sizeM,sizeM+1)
    Background.delete("all")
    time.sleep(delay)
    pTail(1)
    sizeM+=1
    pHead(1)
    retangle(1,0,sizeM)
    time.sleep(delay)
    Background.delete("all")
    retangle(1,0,sizeM)
    pHeadTail(1)
    check = False
    main.update()

def themDau():
    global Mchu
    global sizeM 
    global chu
    global check
    Background.delete("all")
    retangle(1,0,sizeM)
    pHeadTail(1) 
    chu  = chr(ord(chu)+1)
    oneRectangle(2*space,cachLeTren+2*space,len+space,cachLeTren+2*space+cc,"white",chu)
    time.sleep(0.6)
    #tạo đường thẳng nối giữ phần tử thêm vào với phần tử đầu tiên
    muiTenThang(2*space+(len-space)/2,cachLeTren+2*space,2*space+(len-space)/2,cachLeTren+cc)
    time.sleep(0.6)
    #tạo đường thẳng nối phead với phần tử được thêm vào
    muiTenThang(space+3,cachLeTren+cc/2+1,2*space,cachLeTren+2*space)
    time.sleep(0.6)
    Background.delete("all")
    retangle(1,0,sizeM)
    Oh(1)
    pTail(1)
    updataChu(chu,0)
    #hiện lại phần tử thêm vào
    retangle(2,0,1)
    #tạo đường thẳng nối giữ phần tử thêm vào với phần tử đầu tiên
    muiTenThang(2*space+(len-space)/2,cachLeTren+2*space,2*space+(len-space)/2,cachLeTren+cc)
    #tạo đường thẳng nối phead với phần tử được thêm vào
    muiTenThang(space+3,cachLeTren+cc/2+1,2*space,cachLeTren+2*space)
    time.sleep(0.6)
    sizeM +=1
    pHeadTail(3)
    retangle(3,0,sizeM)
    check = False
    main.update()

def hide_mid():
    entry.grid_forget()
    label1.grid_forget()
    label2.grid_forget()
    enter.grid_forget()
    addMiddle.config(bg = "white")
    startMang.config(bg = "white")
    time.sleep(0.3)
def themGiuaS():
    global check 
    if check:
        return
    check=True
    hide_mid()
    addMiddle.config(bg = "red")
    entry.grid(row=7, column=6)
    label1.config(text="Nhap vi tri can them vao",bg ="yellow")
    label1.grid( row =6, column=6)
    def chuyenSangInt():
        global check
        value = entry_var.get()
        if value.isdigit():
            x = int(value)
            if 0<x and x<=sizeM+1:
                if(x ==1):
                        themDau()
                elif(x == sizeM+1):
                        themCuoi()
                else:
                    themGiua(x)
            else:
                label2.config(text="Khong ton tai")
                label2.grid( row =9, column=6)
        else:
            label2.config(text="sai dinh dang")
            label2.grid( row =9, column=6)
        check = False
    enter.config(text="Enter",command=chuyenSangInt)
    enter.grid(row=8, column=6)

def themDauS():
    global check
    if check:
        return
    check = True
    hide_mid()
    addFirst.config(bg="red")
    themDau()
    time.sleep(0.2)
    addFirst.config(bg="white")

def themCuoiS():
    global check
    if check:
        return
    check = True
    hide_mid()
    addLast.config(bg = "red")
    themCuoi()
    time.sleep(0.2)
    addLast.config(bg = "white")

def restart():
    global check 
    if check:
        return
    check = True
    hide_mid()
    startMang.config(bg = "red")
    label1.config(text = "Nhap so luong phan tu list",bg= "green")
    label1.grid(row=6,column=6)
    entry.grid(row=7,column=6)
    def chuyenSoInt():
        global check
        check = False
        global sizeM
        value = entry_var.get()
        if value.isdigit():
            if int(value) > 0:
                sizeM = int(value)
                ktao()

            else:
                label2.config(text ="Phai la duong")
                label2.grid(row=9, column= 6)
        else:
            label2.config(text = "Sai dinh dang")   
            label2.grid(row=9, column= 6)    
    enter.config(text="Enter",command=chuyenSoInt)
    enter.grid(row=8,column=6)
    check = False

#Hàm chạy chương trình
main = tk.Tk()
main.title("Đồ án giữa kì 2, 894")

Background = tk.Canvas(main,width=rong, height= cao, background="sky blue")
Background.grid(row = 0, column = 1,rowspan=20 ,columnspan=4, padx = 4)
ktao()
entry_var = tk.StringVar()
entry = tk.Entry(main, textvariable=entry_var,bg ="pink")
label1 = tk.Label(main, text="")
label2 = tk.Label(main, text="")
enter = tk.Button(main)
check = False

startMang = tk.Button(main, text ="Khởi tạo lại List", command = restart )
startMang.grid(row= 5,column=6)

addFirst = tk.Button(main, text="Thêm vào đầu", command = themDauS)
addFirst.grid(row =2,column=6, padx= 30)

addLast = tk.Button(main, text="Thêm vào cuôi", command = themCuoiS)
addLast.grid(row =3,column=6, padx= 10)

addMiddle = tk.Button(main, text="Thêm vào giua", command = themGiuaS)
addMiddle.grid(row =4,column=6, padx= 10)

main.mainloop()