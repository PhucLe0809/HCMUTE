CREATE DATABASE QLNV
GO

-- Tạo CSDL QLNV
USE QLNV
GO
--Tạo bảng PhongBan
-- Cột Trphong phải có cùng kiểu dữ liệu với cột Manv trong bảng NhanVien
CREATE TABLE dbo.PhongBan(
	MaPB int PRIMARY KEY,
	TenPB char(10) NULL,
	TrPhong char(4) NULL,
	NgNhanChuc date Null
)
GO

-- Tạo cấu trúc bảng Nhân viên
-- Cột MaNQL là khóa ngoại tham chiếu đến cột Manv cũng trong bảng này. Nhưng ta chưa tạo khóa ngoại lúc này để dễ nhập data
-- Khi nhập dữ liệu xong sẽ khai báo thêm khóa ngoại
-- Cột MaNQL phải có cùng kiểu dữ liệu với cột Manv
-- Cột Phong phải có cùng kiểu dữ liệu với cột MaPB trong bảng PhongBan
CREATE TABLE dbo.NhanVien(
	Manv char(4) PRIMARY KEY,
	HoNV char(10) NULL,
	Tenlot char(20) NULL,
	tenNV char(10) NULL,
	NgSinh date NULL,
	Dchi char(50) NULL,
	Phai char(3) NULL,
	Luong int NULL,
	MaNQL char(4) NULL,
	Phong int 
)
Go
-- Nhập giá trị vào bảng Nhân viên, nhập theo đúng thứ tự các thuộc tính trong bảng
-- Chú ý Nhập giá trị trong cột MaNQL phải là các giá trị có trong cột Manv
Insert into Nhanvien Values ('nv01', 'Nguyen', 'Ngoc', 'Hoang', '1972-08-13', '111 Vo Van Ngan', 'Nam', 30000, 'NV02', 1)
Insert into Nhanvien Values ('nv02', 'Nguyen', 'Quang', 'Ngoc', '1975-08-23', '111 Nguyen Van Troi', 'Nam', 25000, 'NV15', 1)
Insert into Nhanvien Values ('nv03', 'Le', 'Thi', 'Ngoc', '1980-08-13', '111 Duong 3/2', 'Nu', 28000, 'NV15', 2)
Insert into Nhanvien Values ('nv04', 'Le', 'Ngoc', 'Hoang', '1982-08-18', '111 Le Van Duyet', 'Nam', 15000, 'NV03', 2)
Insert into Nhanvien Values ('nv05', 'Nguyen', 'Thi', 'Ngoc', '1992-08-13', '108 Vo Van Ngan', 'Nu', 28000, 'NV06', 3)
Insert into Nhanvien Values ('nv06', 'Truong', 'Anh', 'Kiet', '1960-12-13', '11 Hai Ba Trung', 'Nam', 30000, 'NV15', 3)
Insert into Nhanvien Values ('nv07', 'Le', 'Phung', 'Hieu', '1972-08-13', '11 Hau Giang', 'Nam', 10000, 'NV15', 4)
Insert into Nhanvien Values ('nv08', 'Nguyen', 'Bao', 'Hung', '1978-08-23', '10 Tran Hung Dao', 'Nam', 20000, 'NV15', 5)
Insert into Nhanvien Values ('nv09', 'Nguyen', 'Bao', 'Hoang', '1972-08-13', '111 Tran Hung Dao', 'Nam', 10000, 'NV15', 6)
Insert into Nhanvien Values ('nv10', 'Le', 'Hoang', 'Ngoc', '1972-08-13', '11 Lac Long Quan', 'Nam', 10000, 'NV15', 7)
Insert into Nhanvien Values ('nv11', 'Nguyen', 'Bao','Ngoc', '1972-08-13', '111 Minh Phung', 'Nu', 15000, 'NV15', 8)
Insert into Nhanvien Values ('nv12', 'Nguyen', 'Ngoc', 'A', '1982-08-13', '11 Nguyen Duy Trinh', 'Nam', 10000, 'NV11', 8)
Insert into Nhanvien Values ('nv13', 'Le', 'Quang', 'Hoang', '1979-08-23', '10 Ly Chinh Thang', 'Nam', 15000, 'NV15', 9)
Insert into Nhanvien Values ('nv14', 'Nguyen', 'Quang', 'Hoang', '1972-08-13', '11 Le Van Thinh', 'Nam', 10000, 'NV13', 9)
Insert into Nhanvien Values ('nv15', 'Dang', 'Tan', 'Dung', '1960-08-13', '23 Vo Van Ngan', 'Nam', 50000, NULL, 10)
Go
-- Nhập giá trị vào bảng PhongBan, nhập theo đúng thứ tự các thuộc tính trong bảng
-- Kiểu dữ liệu Data nhập theo dạng: 'YYYY-MM-DD' (Year-Month-Day)
-- Chú ý nhập giá trị cột TrPhong là các giá trị có trong cột Manv của bảng Nhân viên
Insert into PhongBan Values (1, 'Nghien cuu', 'nv02', '2013-12-12');
Insert into PhongBan Values (2, 'To chuc', 'nv03', '2013-11-21');
Insert into PhongBan Values (3, 'Vat tu', 'nv06', '2013-1-25');
Insert into PhongBan Values (4, 'Dao tao', 'nv15', '2013-2-19');
Insert into PhongBan Values (5, 'Kinh doanh', 'nv15', '2013-08-18');
Insert into PhongBan Values (6, 'Doi ngoai', 'nv15', '2013-10-17');
Insert into PhongBan Values (7, 'Xay dung', 'nv15', '2013-02-20');
Insert into PhongBan Values (8, 'QL Du an', 'nv11', '2013-12-12');
Insert into PhongBan Values (9, 'Ke toan', 'nv13', '2013-12-12');
Insert into PhongBan Values (10, 'BGD', 'nv15', '2010-11-29');
Go
-- Thêm hai khóa ngoại cho bảng NhanVien
Alter table NHANVIEN WITH CHECK ADD FOREIGN KEY(MaNQL) REFERENCES NhanVien(Manv)
Go
ALTER TABLE NHANVIEN  WITH CHECK ADD FOREIGN KEY(Phong) REFERENCES PhongBan(MaPB)
GO

-- Tạo cấu trúc bảng Địa điểm - Phòng
-- Cột MaPB tham chiếu đến MaPB trong bảng PhongBan nên phải có kiểu dữ liệu giống kiểu dữ liệu của cột MaPB trong bảng PhongBan
Create table DIADIEM_PHONG(
		MaPB int references PhongBan(MaPB),
		DiaDiem char(30),
		Primary key (MaPB, DiaDiem) -- khai báo khóa chính gồm 2 cột
		)
Go
-- Nhập dữ liệu cho bảng DIADIEM_PHONG
Insert into DIADIEM_PHONG Values(1, 'Tang tret - Khu A')
Insert into DIADIEM_PHONG Values(2, 'Tang 1 - Khu A')
Insert into DIADIEM_PHONG Values(3, 'Tang tret - Khu B')
Insert into DIADIEM_PHONG Values(4, 'Tang tret - Khu C')
Insert into DIADIEM_PHONG Values(5, 'Tang tret - Khu E')
Insert into DIADIEM_PHONG Values(6, 'Tang tret - Khu Bát giác')
Insert into DIADIEM_PHONG Values(7, 'Tang tret - Khu Trung tâm')
Insert into DIADIEM_PHONG Values(8, 'Tang 1 - Khu Trung tâm')
Insert into DIADIEM_PHONG Values(9, 'Tang 2 - Khu Trung tâm')
Insert into DIADIEM_PHONG Values(10, 'Tang 3 - Khu Trung tâm')
Go
-- Tạo cấu trúc bảng Dự án
-- Cột Phong là khóa ngoại tham chiếu đến cột MaPB bên bảng PhongBan
Create Table DUAN(
	MaDA char(4) primary key,
	TenDA Char(30),
	DiaDiem char(30),
	Phong int references PhongBan(MaPB)
	)
Go
-- Nhập dữ liệu cho bảng DUAN
Insert into DUAN Values ('DA01', 'Cap thoat nuoc', 'Go Vap', 9)
Insert into DUAN Values ('DA02', 'Ban chung cu', 'Thu Thiem', 5)
Insert into DUAN Values ('DA03', 'Xay biet thu', 'Thu Duc', 7)
Insert into DUAN Values ('DA04', 'Lien ket dao tao', 'Go Vap', 4)
Insert into DUAN Values ('DA05', 'Cung cap vat tu', 'Quan 2', 3)
Insert into DUAN Values ('DA06', 'Huan luyen', 'Go Vap', 4)
Go
-- Tạo cấu trúc bảng PHANCONG
-- Cột MaNV tham chiếu đến cột MaNV trong bảng NhanVien nên chúng phải có cùng kiểu dữ liệu
-- Cột MaDA tham chiếu đến cột MaDA trong bảng DUAN nên chúng phải có cùng kiểu dữ liệu
Create table PhanCong(
	MaNV char(4) references NhanVien(maNV),
	MaDA char(4) references DuAn(MaDA),
	ThoiGian int,
	Primary key (MaNV, MaDA)
	)
Go
-- Nhập dữ liệu
-- Giá trị trong cột MaNV phải có ở cột MaNV trong bảng NhanVien
-- Giá trị trong cột MaDA phải có ở cột MaDA trong bảng DuAN
Insert into PhanCong Values ('nv01', 'DA01', 3)
Insert into PhanCong Values ('nv01', 'DA02', 3)
Insert into PhanCong Values ('nv02', 'DA01', 3)
Insert into PhanCong Values ('nv02', 'DA03', 3)
Insert into PhanCong Values ('nv03', 'DA04', 3)
Insert into PhanCong Values ('nv04', 'DA03', 3)
Insert into PhanCong Values ('nv09', 'DA04', 3)
Insert into PhanCong Values ('nv01', 'DA05', 3)
Insert into PhanCong Values ('nv05', 'DA05', 3)
Insert into PhanCong Values ('nv07', 'DA06', 3)
Insert into PhanCong Values ('nv08', 'DA06', 3)
Go
-- Tạo cấu trúc bảng ThanNhan
-- Cột MaNV tham chiếu đến cột MaNV bên bảng NhanVien nên chúng phải có cùng kiểu dữ liệu
Create table ThanNhan(
		MaNV char(4) references NhanVien(maNV),
		TenTN char(20),
		Phai char(3),
		NgaySinh date,
		QuanHe char(10),
		Primary key (MaNV, TenTN)
		)
Go

--Nhập dữ liệu
-- Giá trị trong cột MaNV phải có ở cột MaNV trong bảng NhanVien
Insert into ThanNhan Values ('nv01', 'Nguyen Ngoc Huy', 'Nam', '2018-3-26','con')
Insert into ThanNhan Values ('nv01', 'Nguyen Ngoc Hoa', 'Nu', '2020-3-26','con')
Insert into ThanNhan Values ('nv02', 'Nguyen Ngoc Huy', 'Nam', '2018-3-26','con')
Insert into ThanNhan Values ('nv02', 'Nguyen Ngoc Hoa', 'Nu', '2020-3-26','con')
Insert into ThanNhan Values ('nv15', 'Dang Ngoc Hoa', 'Nu', '2020-3-26','con')
Insert into ThanNhan Values ('nv01', 'Nguyen Nguyen Hung', 'Nam', '2020-3-26','con')

-- 1.	Hãy cho biết tên các dự án mà nhân viên có mã ‘NV01’ tham gia
select nv.Manv, da.MaDA, da.TenDA
from PhanCong as pc 
inner join (select NhanVien.Manv from NhanVien where MaNV = 'nv01') as nv
on pc.MaNV = nv.Manv
inner join DUAN as da
on pc.MaDA = da.MaDA

-- 2.	Tính tổng thời gian tham gia các dự án của mỗi nhân viên
select nv.Manv, count(pc.MaDA)
from NhanVien as nv left outer join PhanCong as pc
on nv.Manv = pc.MaNV
group by nv.Manv

-- 3.	Cho biết họ tên các nhân viên chưa tham gia dự án nào
select nvv.MaNV, nvv.tenNV
from 
	(select nv.Manv from NhanVien as nv
	except
	select pc.MaNV from PhanCong as pc) as q
	inner join NhanVien as nvv
	on q.Manv = nvv.Manv

-- a.   Tìm ngày sinh và địa chỉ của nhân viên “Nguyễn Bảo Hùng”
select nv.NgSinh, nv.Dchi from dbo.NhanVien as nv
where nv.HoNV = 'Nguyen'
and nv.Tenlot = 'Bao'
and nv.tenNV = 'Hung'

-- b.	Tìm tên và địa chỉ của các nhân viên làm việc cho phòng “Nghiên cứu”
select nv.tenNV, nv.Dchi
from dbo.NhanVien as nv join dbo.PhongBan as pb
on nv.Phong = pb.MaPB and pb.TenPB = 'Nghien cuu'

-- c.	Với mỗi dự án được triển khai ở Gò Vấp, cho biết mã dự án, mã phòng quản lý và họ tên, ngày sinh trưởng phòng của phòng đó 
select da.MaDA, da.Phong, nv.tenNV, nv.NgSinh
from dbo.PhongBan as pb inner join dbo.DUAN as da
on pb.MaPB = da.Phong and da.DiaDiem = 'Go Vap'
inner join dbo.NhanVien as nv
on nv.Manv = PB.TrPhong

-- d.	Với mỗi nhân viên, cho biết họ tên nhân viên và họ tên của người quản lý nhân viên đó 
select nv1.tenNV, nv2.tenNV
from dbo.NhanVien as nv1 left outer join dbo.NhanVien as nv2
on nv1.MaNQL = nv2.Manv

-- e.	Cho biết mã nhân viên, họ và tên của các nhân viên của phòng “Nghiên cứu” có mức lương từ 30000 đến 50000
select nv.MaNV, nv.tenNV
from NhanVien as nv inner join PhongBan as pb
on nv.Phong = pb.MaPB and pb.TenPB = 'Nghien cuu'
and nv.Luong between 30000 and 50000

-- f.	Cho biết mã nhân viên, họ tên nhân viên và mã dự án, tên dự án của các dự án mà họ tham gia 
select nv.Manv, nv.tenNV, pc.MaDA, da.TenDA
from NhanVien as nv inner join PhanCong as pc
on nv.Manv = pc.MaNV
inner join DUAN as da
on pc.MaDA = da.MaDA

-- g.	Cho biết mã nhân viên, họ tên của những người không có người quản lý 
select nv.Manv, nv.tenNV
from NhanVien as nv
where nv.MaNQL is null

-- h.	Cho biết họ tên của các trưởng phòng có thân nhân 
select distinct nv.tenNV
from PhongBan as pb inner join ThanNhan as tn
on pb.TrPhong = tn.MaNV
inner join NhanVien as nv
on tn.MaNV = nv.Manv

-- i.	Tính tổng lương nhân viên, lương cao nhất, lương thấp nhất và mức lương trung bình 
select sum(nv.Luong), max(nv.Luong), min(nv.Luong), avg(nv.Luong)
from Nhanvien as nv

-- j.	Cho biết tổng số nhân viên và mức lương trung bình của phòng “Nghiên cứu”
select count(nv.Manv), avg(nv.Luong)
from PhongBan as pb inner join NhanVien as nv
on nv.Phong = pb.MaPB and pb.TenPB = 'Nghien cuu'

-- k.	Với mỗi phòng, cho biết mã phòng, số lượng nhân viên và mức lương trung bình 
select pb.MaPB, count(nv.Manv), avg(nv.Luong)
from PhongBan as pb inner join NhanVien as nv
on nv.Phong = pb.MaPB
group by pb.MaPB

-- l.	Với mỗi dự án, cho biết mã dự án, tên dự án và tổng số nhân viên tham gia 
select da.MaDA, da.TenDA, count(pb.MaNV)
from DUAN as da inner join PhanCong as pb
on da.MaDA = pb.MaDA
group by da.MaDA, da.TenDA

-- m.	Với mỗi dự án có nhiều hơn 2 nhân viên tham gia, cho biết mã dự án, tên dự án và số lượng nhân viên tham gia 
select da.MaDA, da.TenDA, count(pb.MaNV)
from DUAN as da inner join PhanCong as pb
on da.MaDA = pb.MaDA
group by da.MaDA, da.TenDA
having count(pb.MaNV) > 2

-- n.	Với mỗi dự án, cho biết mã số dự án, tên dự án và số lượng nhân viên phòng số 5 tham gia 
select da.MaDA, da.TenDA, count(nv.MaNV)
from DUAN as da inner join PhanCong as pb
on da.MaDA = pb.MaDA
inner join NhanVien as nv
on pb.MaNV = nv.Manv and nv.Phong = 5
group by da.MaDA, da.TenDA

-- o.	Với mỗi phòng có nhiều hơn 2 nhân viên, cho biết mã phòng và số lượng nhân viên có lương lớn hơn 25000
select pb.MaPB, 
	   count(nv.MaNV),
	   sum(case when nv.Luong > 25000 then 1 else 0 end)
from PhongBan as pb inner join NhanVien as nv
on pb.MaPB = nv.Phong
group by pb.MaPB
having count(nv.MaNV) >= 2

-- p.	Với mỗi phòng có mức lương trung bình lớn hơn 30000, cho biết mã phòng, tên phòng, số lượng nhân viên của phòng đó 
select pb.MaPB, pb.TenPB, count(nv.MaNV)
from PhongBan as pb inner join NhanVien as nv
on pb.MaPB = nv.Phong
group by pb.MaPB, pb.TenPB
having avg(nv.Luong) >= 30000

-- q.	Với mỗi phòng có mức lương trung bình lớn hơn 30000, cho biết mã phòng, tên phòng, số lượng nhân viên nam của phòng đó
select pb.MaPB, pb.TenPB, 
	   count(nv.MaNV) as SLNhanVien,
	   sum(case when nv.Phai = 'Nu' then 1 else 0 end) as NVNu
from PhongBan as pb inner join NhanVien as nv
on pb.MaPB = nv.Phong
group by pb.MaPB, pb.TenPB
having avg(nv.Luong) >= 30000



