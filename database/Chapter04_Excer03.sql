create database NVCOQUAN
go

use NVCOQUAN
go

create table COQUAN
(
	MSCOQUAN char(10) primary key,
	TENCOQUAN char(50),
	DIACHI char(50)
)
create table NV
( 
	MSNV char(10) primary key,
	TEN char(50) ,
	MSCOQUAN char(10) references COQUAN(MSCOQUAN),
	CONGVIEC char(10),
	LUONG int 
)

insert into COQUAN values ('50', 'Anh Thu', 'Do Son')
insert into COQUAN values ('15', 'AnhThu', 'Cao Bang')
insert into COQUAN values ('20', 'AT', 'Lao Cai')
insert into COQUAN values ('25', 'AThu', 'Ha Giang')

insert into NV values ('NV01', 'AT', '50', 'an', '2500')
insert into NV values ('NV02', 'AThu', '25', 'uong', '2500')
insert into NV values ('NV03', 'Anh Thu', '20', 'an', '3000')
insert into NV values ('NV04', 'AT', '15', '10', '2000')

-- 	a. Tìm tên những nhân viên ở cơ quan có mã số là 50
select nv.TEN
from COQUAN as cq inner join NV
on cq.MSCOQUAN = '50' and cq.MSCOQUAN = nv.MSCOQUAN

-- 	b. Tìm mã số tất cả các cơ quan từ quan hệ NV
select *
from NV inner join COQUAN
on nv.MSCOQUAN = COQUAN.MSCOQUAN

-- 	c. Tìm tên các nhân viên ở cơ quan có mã số là 15,20,25
select nv.TEN
from COQUAN as cq inner join NV
on cq.MSCOQUAN = nv.MSCOQUAN
and (cq.MSCOQUAN = '15' or cq.MSCOQUAN = '20' or cq.MSCOQUAN = '25')

-- 	d. Tìm tên những người làm việc ở Đồ Sơn
select NV.TEN
from COQUAN as cq inner join NV
on cq.MSCOQUAN = nv.MSCOQUAN and cq.DIACHI = 'Do Son'

