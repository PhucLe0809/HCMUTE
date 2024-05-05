create database THUVIEN
go

use THUVIEN
go

create table NXB
( 
	MaNXB char(10) primary key,
	TenNXB char(50) null,
	DiaChi char(50) null,
	SoDT char(10) null
	)
create table DAUSACH 
( 
	MaSach char(10) primary key,
	Tua char(50) null,
	MaNXB char(10) references NXB(MaNXB) 
	)
create table TACGIA
( 
	MaSach char(10) references DAUSACH(MaSach),
	TenTacGia char(50) ,
	primary key (MaSach, TenTacGia) )
create table DOCGIA
(
	MaDG char(10) primary key,
	TenDG char(50),
	DiaChi char(50),
	SoDT char(10)
	)
create table CUONSACH
(
	MaSach char(10) references DAUSACH(MaSach),
	MaCuon char(10) primary key,
	ViTri char(10)
	)
create table MUON 
(
	MaCuon char(10) references CUONSACH(MaCuon),
	MaDG char(10) references DOCGIA(MaDG),
	NgayMuon date,
	NgayTra date,
	primary key (MaCuon, MaDG) )

insert into NXB values ('101', 'Addison Wesley', 'Sai Gon', '0')
insert into NXB values ('102', 'ABC', 'Vung Tau', '1')
insert into NXB values ('103', 'xyz', 'Ha Noi', '2')
insert into NXB values ('104', 'klm', 'Nha Trang', '3')
insert into NXB values ('105', 'opq', 'Hoi An', '4')
insert into NXB values ('106', 'athu', 'Binh Duong', '5')
insert into NXB values ('107', 'thu', 'Ha Giang', '6')
insert into NXB values ('108', 'anh', 'Hoc Mon', '7')
insert into NXB values ('109', 'anhthu', 'Quan 1', '8')
insert into NXB values ('110', 'thuanh', 'An Giang', '9')

insert into DAUSACH values ('MS01', 'AT', '110')
insert into DAUSACH values ('MS02', 'ATHU', '109')
insert into DAUSACH values ('MS03', 'ANHTHU', '107')
insert into DAUSACH values ('MS04', 'TTAT', '108')
insert into DAUSACH values ('MS05', 'ANHT', '106')
insert into DAUSACH values ('MS06', 'AT', '110')
insert into DAUSACH values ('MS07', 'ATGT', '101')
insert into DAUSACH values ('MS08', 'ATAT', '102')
insert into DAUSACH values ('MS09', 'AATT', '103')
insert into DAUSACH values ('MS10', 'ATT', '110')

insert into TACGIA values ('MS01', 'Hemingway')
insert into TACGIA values ('MS02', 'Hem')
insert into TACGIA values ('MS03', 'Hemi')
insert into TACGIA values ('MS04', 'Hemin')
insert into TACGIA values ('MS04', 'Heming')
insert into TACGIA values ('MS06', 'He')
insert into TACGIA values ('MS07', 'Hemingw')
insert into TACGIA values ('MS08', 'Hemingway')
insert into TACGIA values ('MS10', 'AnhThu')
insert into TACGIA values ('MS10', 'AT')

insert into DOCGIA values ('DG01', 'Anh Thu', 'Binh Dinh', '0')
insert into DOCGIA values ('DG02', 'Minh Duc', 'Dong Nai', '1')
insert into DOCGIA values ('DG03', 'Vu Anh', 'Ben Tre', '2')
insert into DOCGIA values ('DG04', 'Thuy Tram', 'Binh Dinh', '3')
insert into DOCGIA values ('DG05', 'Manh Tuong', 'Dong Nai', '4')
insert into DOCGIA values ('DG06', 'Yen Vy', 'Long An', '5')
insert into DOCGIA values ('DG07', 'Kim Man', 'An Giang', '6')
insert into DOCGIA values ('DG08', 'Huu Loc', 'My Tho', '7')
insert into DOCGIA values ('DG09', 'Nguyen Van A', 'Binh Dinh', '8')
insert into DOCGIA values ('DG10', 'Dang Van B', 'Lao Cai', '9')

insert into CUONSACH values('MS01', 'MC01', 'a')
insert into CUONSACH values('MS02', 'MC02', 'b')
insert into CUONSACH values('MS01', 'MC03', 'c')
insert into CUONSACH values('MS03', 'MC04', 'd')
insert into CUONSACH values('MS05', 'MC05', 'e')
insert into CUONSACH values('MS07', 'MC06', 'f')
insert into CUONSACH values('MS08', 'MC07', 'g')
insert into CUONSACH values('MS10', 'MC08', 'k')
insert into CUONSACH values('MS01', 'MC09', 'l')
insert into CUONSACH values('MS01', 'MC10', 'i')

insert into MUON values ('MC01', 'DG01', '2023-09-19','2023-09-22')
insert into MUON values ('MC08', 'DG05', '2023-09-19','2023-09-22')
insert into MUON values ('MC02', 'DG08', '2023-09-19','2023-09-22')
insert into MUON values ('MC07', 'DG09', '2023-09-19','2023-09-22')
insert into MUON values ('MC10', 'DG02', '2023-09-19','2023-09-22')
insert into MUON values ('MC03', 'DG03', '2023-09-19','2023-09-22')
insert into MUON values ('MC04', 'DG06', '2023-09-19','2023-09-22')
insert into MUON values ('MC06', 'DG04', '2023-09-19','2023-09-22')
insert into MUON values ('MC09', 'DG07', '2023-09-19','2023-09-22')
insert into MUON values ('MC05', 'DG10', '2023-09-19','2023-09-22')

-- a.	Cho biết Địa chỉ và số điện thoại của Nhà xuất bản “Addison Wesley”
select nxb.DiaChi, nxb.SoDT
from NXB
where nxb.TenNXB = 'Addison Wesley'

-- b.	Cho biết mã sách và Tựa sách của những cuốn sách được xuất bản bởi nhà xuất bản “Addison Wesley”
select ds.MaSach, ds.Tua
from NXB inner join DAUSACH as ds
on nxb.TenNXB = 'Addison Wesley' and nxb.MaNXB = ds.MaNXB

-- c.	Cho biết mã sách và Tựa sách của những cuốn sách có tác giả là “Hemingway”
select ds.MaSach, ds.Tua
from DAUSACH as ds inner join TACGIA as tg
on tg.TenTacGia = 'Hemingway' and ds.MaSach = tg.MaSach

-- d.	Với mỗi đầu sách, cho biết tựa và số lượng cuốn sách mà thư viện đang sở hữu 
select ds.MaSach, count(cs.MaCuon)
from DAUSACH as ds inner join CUONSACH as cs
on ds.MaSach = cs.MaSach
group by ds.MaSach

-- e.	Với mỗi độc giả, hãy cho biết Tên, địa chỉ và số lượng cuốn sách mà người đó đã mượn 
select dg.MaDG, count(mn.MaCuon)
from DOCGIA as dg left outer join MUON as mn
on dg.MaDG = mn.MaDG
group by dg.MaDG

-- f.	Cho biết mã cuốn, tựa sách và vị trí của những cuốn sách được xuất bản bởi nhà xuất bản “Addison Wesley”
select nxb.TenNXB, cs.MaCuon, ds.Tua, cs.ViTri
from 
	NXB inner join DAUSACH as ds
	on nxb.TenNXB = 'Addison Wesley' and nxb.MaNXB = ds.MaNXB
	inner join CUONSACH as cs
	on ds.MaSach = cs.MaSach

-- g.	Với mỗi đầu sách, hãy cho biết Tên nhà xuất bản và số lượng tác giả
select q.MaSach, q.MaNXB, q.TenNXB, count(tg.MaSach) as SLTG
from 
    (select ds.MaSach, nxb.MaNXB, nxb.TenNXB
	from DAUSACH as ds inner join NXB
	on ds.MaNXB = nxb.MaNXB) as q
	left outer join TACGIA as tg
	on q.MaSach = tg.MaSach
group by q.MaSach, q.MaNXB, q.TenNXB

-- h.	Hãy cho biết Tên, địa chỉ, số điện thoại của những độc giả đã mượn từ 5 cuốn sách trở lên 
select dg.*, count(q.SLCuon) as SLCuon
from 
	(select mn.MaDG, count(mn.MaCuon) as SLCuon
	from MUON as mn
	group by mn.MaDG
	having count(mn.MaCuon) >= 5) as q
	inner join DOCGIA as dg
	on q.MaDG = dg.MaDG
group by dg.MaDG, dg.MaDG, dg.TenDG, dg.DiaChi, dg.SoDT;

-- i.	Cho biết mã NXB, tên NXB và số lượng đầu sách của NXB đó trong CSDL
select nxb.MaNXB, nxb.TenNXB, count(ds.MaSach) as SLDauSach
from NXB left outer join DAUSACH as ds
on nxb.MaNXB = ds.MaNXB
group by nxb.MaNXB, nxb.TenNXB

-- j.	Cho biết mã NXB, tên NXB và địa chỉ của những NXB có từ 100 đầu sách trở lên
select nxb.MaNXB, nxb.TenNXB, nxb.DiaChi
from NXB left outer join DAUSACH as ds
on nxb.MaNXB = ds.MaNXB
group by nxb.MaNXB, nxb.TenNXB, nxb.DiaChi
having count(ds.MaSach) >= 100

-- k.	Cho biết mã NXB, tên NXB, và số lượng tác giả đã hợp tác với NXB đó 
select q.MaNXB, q.TenNXB, count(tg.MaSach) as SLTG
from 
    (select ds.MaSach, nxb.MaNXB, nxb.TenNXB
	from DAUSACH as ds inner join NXB
	on ds.MaNXB = nxb.MaNXB) as q
	left outer join TACGIA as tg
	on q.MaSach = tg.MaSach
group by q.MaNXB, q.TenNXB

-- l.	Tựa và số lượng tác giả của những cuốn sách có tác giả là “Hemingway” mà độc giả “Nguyễn Văn A” đã từng mượn 
select two.MaSach, two.Tua, count(tg.MaSach) as SLTacGia
from 
	(select one.MaSach, one.Tua
	from 
		(select ds.MaSach, ds.Tua
			from DAUSACH as ds inner join NXB
			on ds.MaNXB = nxb.MaNXB) as one
		inner join TACGIA as tg
		on tg.TenTacGia = 'Hemingway' and one.MaSach = tg.MaSach
	) as two
inner join
	(select cs.MaSach, cs.MaCuon
	from
		(select dg.MaDG, mn.MaCuon
			from DOCGIA as dg inner join MUON as mn
			on dg.TenDG = 'Nguyen Van A' and dg.MaDG = mn.MaDG) as three
		inner join CUONSACH as cs
		on three.MaCuon = cs.MaCuon
	) as four
on two.MaSach = four.MaSach
inner join TACGIA as tg
on two.MaSach = tg.MaSach
group by two.MaSach, two.Tua







