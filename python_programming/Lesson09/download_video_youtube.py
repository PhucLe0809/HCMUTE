import subprocess
import tkinter as tk
from tkinter import *
from tkinter import ttk
from pytube import YouTube
from tkinter import messagebox, filedialog
import os

def Widgets():
    head_label = Label(root, text="YouTube Video Downloader Using Tkinter",
                    padx=15,
                    pady=15,
                    font="SegoeUI 14",
                    bg="palegreen1",
                    fg="red")
    head_label.grid(row=1,
                    column=1,
                    pady=10,
                    padx=5,
                    columnspan=2)

    link_label = Label(root,
                    text="YouTube link :",
                    bg="salmon",
                    pady=5,
                    padx=5)
    link_label.grid(row=2,
                    column=0,
                    pady=5,
                    padx=5)

    root.linkText = Entry(root,
                        width=35,
                        textvariable=video_Link,
                        font="Arial 14")
    root.linkText.grid(row=2,
                    column=1,
                    pady=5,
                    padx=5,
                    columnspan=2)

    destination_label = Label(root,
                            text="Destination :",
                            bg="salmon",
                            pady=5,
                            padx=9)
    destination_label.grid(row=3,
                        column=0,
                        pady=5,
                        padx=5)

    root.destinationText = Entry(root,
                                width=27,
                                textvariable=download_Path,
                                font="Arial 14")
    root.destinationText.grid(row=3,
                            column=1,
                            pady=5,
                            padx=5)

    browse_B = Button(root,
                    text="Browse",
                    command=Browse,
                    width=10,
                    bg="bisque",
                    relief=GROOVE)
    browse_B.grid(row=3,
                column=2,
                pady=1,
                padx=1)

    get_quality_B = Button(root,
                        text="Get Quality",
                        command=GetQuality,
                        width=15,
                        bg="skyblue",
                        relief=GROOVE)
    get_quality_B.grid(row=2,
                    column=3,
                    pady=5,
                    padx=5)

    global quality_combo
    quality_label = Label(root,
                        text="Select Quality :",
                        bg="salmon",
                        pady=5,
                        padx=9)
    quality_label.grid(row=4,
                        column=0,
                        pady=5,
                        padx=5)

    # ComboBox to display video resolutions
    quality_combo = ttk.Combobox(root, width=10)
    quality_combo.grid(row=4, column=1, pady=5, padx=5)

    Download_B = Button(root,
                        text="Download Video",
                        command=Download,
                        width=20,
                        bg="thistle1",
                        pady=10,
                        padx=15,
                        relief=GROOVE,
                        font="Georgia, 13")
    Download_B.grid(row=5,
                    column=1,
                    pady=20,
                    padx=20)

def Browse():
    download_Directory = filedialog.askdirectory(
        initialdir="YOUR DIRECTORY PATH", title="Save Video")
    download_Path.set(download_Directory)

def GetQuality():
    try:
        video_url = video_Link.get()
        getVideo = YouTube(video_url)
        resolutions = {stream.resolution for stream in getVideo.streams.filter(progressive=False) if stream.resolution}
        resolutions = sorted(resolutions, key=lambda x: int(x[:-1]), reverse=True)
        if resolutions:
            quality_combo['values'] = resolutions
            quality_combo.current(0)
        else:
            messagebox.showerror("Error", "No available video quality.")
    except Exception as e:
        messagebox.showerror("Error", str(e))
        
def Download():
    try:
        Youtube_link = video_Link.get()
        download_Folder = download_Path.get()
        selected_quality = quality_combo.get()
        
        getVideo = YouTube(Youtube_link)
        videoStream = getVideo.streams.filter(progressive=False, file_extension='mp4', resolution=selected_quality).first()
        
        if videoStream:
            videoStream.download(download_Folder)
            messagebox.showinfo("SUCCESSFULLY", f"DOWNLOADED AND SAVED IN\n{download_Folder}")
        else:
            messagebox.showerror("Error", "No available video to download.")
    except Exception as e:
        messagebox.showerror("Error", str(e))

root = tk.Tk()
root.geometry("640x320")
root.resizable(False, False)
root.title("YouTube Video Downloader")
root.config(background="PaleGreen1")

video_Link = StringVar()
download_Path = StringVar()
quality_combo = None

Widgets()

root.mainloop()
