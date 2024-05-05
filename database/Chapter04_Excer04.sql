create database SUAXE
go

use SUAXE
go

create table THO(
	MaTho char(50) primary key,
	TenTho char(50) null,
	Nhom int null,
	NhomTruong char(50)
)
go
create table CONGVIEC (
	MaCV char(50) primary key,
	NoiDungCV char(50) null
)
go
create table KHACHHANG (
	MaKH char(50) primary key,
	TenKH char(50) null,
	DiaChi char(50) null,
	DienThoai char(50) null
)
go
create table HOPDONG (
	SoHD char(50) primary key,
	NgayHD datetime not null,
	MaKH char(50) references KHACHHANG(MaKH),
	SoXe char(20) null,
	TriGiaHD char(20) null,
	NgayGiaoDuKien datetime ,
	NgayNghiemThu datetime
)
go

create table CHITIET_HD (
	SoHD char(50) references HOPDONG(SOHD),
	MaCV char(50) references CONGVIEC(MaCV),
	TriGiaCV char(50) null,
	MaTho char(50) references THO(MaTho),
	KhoanTHo char(50) null,
	primary key ( SoHD, MaCV, MaTho)
)
go
create table PHIEUTHU(
	SoPT char(50) primary key,
	NgayLapPT datetime ,
	SoHD char(50) references HOPDONG(SoHD),
	MaKH char(50) references KHACHHANG(MaKH),
	HoTen char(50) null,
	SoTienThu char(50) null
)
go
insert into THO values ('10THO', 'ManhTuong' , '3', '50THO')
insert into THO values ('15THO', 'AnhThu' , '4', '55THO')
insert into THO values ('20THO', 'VuAnh' , '5', '20THO')
insert into THO values ('25THO', 'ThuyTram' , '6', '50THO')
insert into THO values ('30THO', 'YenVy' , '3', '40THO')
insert into THO values ('35THO', 'MinhNham' , '5', '25THO')
insert into THO values ('40THO', 'VuNguyen' , '7', '55THO')
insert into THO values ('45THO', 'HoangTuan' , '4', '50THO')
insert into THO values ('50THO', 'TuDao' , '4', '40THO')
insert into THO values ('55THO', 'VietHoan' , '5', '55THO')


insert into CONGVIEC values ('SX1', 'SuaXe1')
insert into CONGVIEC values ('SX2', 'SuaXe2')
insert into CONGVIEC values ('SX3', 'SuaXe3')
insert into CONGVIEC values ('SX4', 'SuaXe4')
insert into CONGVIEC values ('BD1', 'BaoDuong1')
insert into CONGVIEC values ('BD2', 'BaoDuong2')
insert into CONGVIEC values ('BD3', 'BaoDuong3')
insert into CONGVIEC values ('BD4', 'BaoDuong4')
insert into CONGVIEC values ('BD5', 'BaoDuong5')
insert into CONGVIEC values ('BD6', 'BaoDuong6')


insert into KHACHHANG values ('KH1', 'AnhVu', 'BenTre', '000')
insert into KHACHHANG values ('KH2', 'ThuAnh', 'BinhDinh', '001')
insert into KHACHHANG values ('KH3', 'TramThuy', 'BinhDinh', '002')
insert into KHACHHANG values ('KH4', 'TuongManh', 'DongNai', '003')
insert into KHACHHANG values ('KH5', 'VyYen', 'LongAn', '004')
insert into KHACHHANG values ('KH6', 'NhamMinh', 'DongNai', '005')
insert into KHACHHANG values ('KH7', 'TuanHoang', 'DongNai', '006')
insert into KHACHHANG values ('KH8', 'NguyenVu', 'DongNai', '007')

insert into HOPDONG values ('1', '2012-12-25', 'KH1', 'SX1', '20000000', '2012-12-26', '2012-12-29')
insert into HOPDONG values ('2', '2012-12-26', 'KH2', 'SX2', '30000000', '2012-12-27', '2012-12-30')
insert into HOPDONG values ('3', '2012-12-27', 'KH3', 'SX3', '40000000', '2012-12-28', '2012-12-31')
insert into HOPDONG values ('4', '2012-12-28', 'KH4', 'SX4', '50000000', '2012-12-29', '2013-1-1')
insert into HOPDONG values ('5', '2012-12-29', 'KH5', 'SX5', '60000000', '2012-12-30', '2013-1-2')
insert into HOPDONG values ('6', '2012-12-30', 'KH6', 'SX6', '70000000', '2013-1-1', '2013-1-3')
insert into HOPDONG values ('7', '2012-12-31', 'KH7', 'SX7', '80000000', '2013-1-2', '2013-1-4')
insert into HOPDONG values ('8', '2013-1-1', 'KH8', 'SX8', '90000000', '2013-1-3', '2013-1-5')
insert into HOPDONG values ('9', '2013-1-2', 'KH8', 'SX9', '100000000', '2013-1-4', '2013-1-6')


insert into CHITIET_HD values ('1', 'SX2' , '200000' , '10THO' , '100000')
insert into CHITIET_HD values ('2', 'SX3' , '300000' , '15THO' , '200000')
insert into CHITIET_HD values ('4', 'SX4' , '400000' , '20THO' , '300000')
insert into CHITIET_HD values ('5', 'BD2' , '500000' , '30THO' , '400000')
insert into CHITIET_HD values ('8', 'BD3' , '600000' , '35THO' , '500000')
insert into CHITIET_HD values ('2', 'BD1' , '700000' , '40THO' , '600000')
insert into CHITIET_HD values ('3', 'BD1' , '800000' , '45THO' , '700000')
insert into CHITIET_HD values ('6', 'SX1' , '900000' , '50THO' , '800000')

insert into PHIEUTHU values ('1', '2012-12-28' , '3' , 'KH1' , 'VuAnh', '200000')
insert into PHIEUTHU values ('2', '2012-12-29' , '4' , 'KH2' , 'AnhThu', '300000')
insert into PHIEUTHU values ('3', '2012-12-30' , '5' , 'KH3' , 'ManhTuong', '400000')
insert into PHIEUTHU values ('4', '2012-12-31' , '6' , 'KH4' , 'YenVy', '500000')
insert into PHIEUTHU values ('5', '2013-1-1' , '7' , 'KH5' , 'ThuyTram', '600000')
insert into PHIEUTHU values ('6', '2013-1-2' , '8' , 'KH6' , 'VuNguyen', '700000')
insert into PHIEUTHU values ('7', '2013-1-3' , '9' , 'KH7' , 'HoangTuan', '800000')
insert into PHIEUTHU values ('8', '2013-1-4' , '1' , 'KH8' , 'MinhNham', '900000')
insert into PHIEUTHU values ('9', '2013-1-5' , '2' , 'KH5' , 'TuDao', '1000000')
insert into PHIEUTHU values ('10', '2013-1-6' , '3' , 'KH3' , 'VietHoan', '1100000')

-- 1.	Cho biết danh sách các người thợ hiện không tham gia vào một  hợp đồng sửa chữa nào.
select THO.MaTho, TenTho
from THO left outer join CHITIET_HD on THO.MaTho=CHITIET_HD.MaTho
where SoHD is null

-- 2.	Cho biết danh sách những hợp đồng đã thanh lý nhưng chưa được thanh toán tiền đầy đủ.
select A.SoHD
from 
	(select HOPDONG.SoHD, TriGiaHD, sum(SoTienThu) as SoTienDaThu
	from HOPDONG inner join PHIEUTHU on HOPDONG.SoHD=PHIEUTHU.SoHD
	group by HOPDONG.SoHD, TriGiaHD) A
where A.TriGiaHD > A.SoTienDaThu

-- 3.	Cho biết danh sách những hợp đồng cần phải hoàn tất trước ngày 31/12/2002
select SoHD
from HOPDONG
where HOPDONG.NgayGiaoDuKien < '2002-12-31'

-- 4.	Cho biết người thợ nào thực hiện công việc nhiều nhất.
select THo.MaTho, TenTho
from (
	select MaTho, count(MaCV) as SLCV 
	from CHITIET_HD
	group by MaTho
) B inner join Tho on B.MaTho = THO.MaTho
where SLCV = (
		select MAX(SLCV) as MAXCV
		from (
			select MaTho, count(MaCV) as SLCV 
			from CHITIET_HD
			group by MaTho
	) A)

-- 5.	Cho biết người thợ nào có tổng trị giá công việc được giao cao nhất.
select THO.MaTho, TenTho
from (select MaTho, sum(TriGiaCV) as TongTGCV
	from CHITIET_HD 
	group by MaTho) B
	inner join THO on B.MaTho= THO.MaTho
where TongTGCV =( select max(TongTGCV) as TongMax
					from
					(select MaTho, sum(TriGiaCV) as TongTGCV
					from CHITIET_HD 
					group by MaTho) A )





