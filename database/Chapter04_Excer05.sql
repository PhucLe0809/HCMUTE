create database THPT
go

use THPT
go

create table MHOC 
(
	MAMH char(10) primary key,
	TENMH char(10),
	SOTIET int 
	)
create table GV 
(
	MAGV char(10) primary key,
	TENGV char(50) ,
	MAMH char(10) references MHOC(MAMH) 
	)

create table BUOITHI
(
	HKY int ,
	NGAY date,
	GIO time,
	PHG char(10),
	MAMH char(10) references MHOC(MAMH),
	TGTHI time,
	primary key (HKY,NGAY,GIO,PHG,MAMH,TGTHI)
	)

create table PC_COI_THI
(
	MAGV char(10) references GV(MAGV),
	HK int,
	NGAY date,
	GIO time,
	PHG char(10),
	primary key (MAGV,HK,NGAY,GIO,PHG)
	)

insert into MHOC values ('VH', 'VAN HOC', '4')
insert into MHOC values ('TH', 'TOAN HOC', '3')
insert into MHOC values ('VL', 'VAT LI', '5')
insert into MHOC values ('HH', 'HOA HOC', '4')

insert into GV values('GV01', 'Anh Thu', 'VH')
insert into GV values('GV02', 'AnhThu', 'HH')
insert into GV values('GV03', 'AT', 'VL')
insert into GV values('GV04', 'AThu', 'TH')

insert into BUOITHI values('1', '2023-09-12', '13:30:00', 'A101','VH','14:45:00')
insert into BUOITHI values('1', '2023-09-12', '13:30:00', 'A103','HH','14:45:00')
insert into BUOITHI values('2', '2023-09-12', '13:30:00', 'A122','TH','14:45:00')
insert into BUOITHI values('2', '2023-09-12', '13:30:00', 'A132','VL','14:45:00')

insert into PC_COI_THI values ('GV04','1','2023-09-12','13:30:00', 'A101')
insert into PC_COI_THI values ('GV03','1','2023-09-12','13:30:00', 'A103')
insert into PC_COI_THI values ('GV01','1','2023-09-12','13:30:00', 'A101')
insert into PC_COI_THI values ('GV02','1','2023-09-12','13:30:00', 'A101')

-- a. Danh sách các giáo viên dạy các môn học có số tiết từ 45 trở lên
select MAGV, TENGV
from GV inner join MHOC on GV.MAMH=MHOC.MAMH
where SOTIET >= 45

-- b. Danh sách giáo viên được phân công gác thi trong học kỳ 1
select GV.MAGV, TENGV
from GV inner join PC_COI_THi on GV.MAGV=PC_COI_THI.MAGV
where HK = 1

-- c. Danh sách giáo viên không được phân công gác thi trong học kỳ 1
select GV.MAGV, TENGV
from GV left outer join PC_COI_THI on GV.MAGV=PC_COI_THI.MAGV
where HK != 1

-- d. Cho biết lịch thi môn văn (TENMH = ‘VĂN HỌC’)
select HKY, NGAY, GIO, PHG, TGTHI
from BUOITHI inner join MHOC on BUOITHI.MAMH= MHOC.MAMH
where TENMH = 'VAN HOC'

-- e. Cho biết các buổi gác thi của các giáo viên chủ nhiệm môn văn (TENMH = ‘VĂN HỌC’).
select PC_COI_THI.MAGV, HK, NGAY, GIO, PHG
from (  select MAGV
		from GV inner join MHOC on GV.MAMH=MHOC.MAMH
		where TENMH ='VAN HOC' ) A
inner join PC_COI_THI on A.MAGV = PC_COI_THI.MAGV
