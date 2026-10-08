--- new query -> ket noi db truoc

create database QLSV_HoTenSV
go

--- sau do moi chay toan bo code duoi

use QLSV_HoTenSV
go

create table tblSinhVien (
ID int identity(1,1) primary key,
TenSV nvarchar(50) not null,
NgaySinh datetime not null,
GioiTinh int check(GioiTinh in (0,1)) not null,
TrinhDoHocVan int check(TrinhDoHocVan between 0 and 3) not null,
QueQuan nvarchar(30),
DiaChi nvarchar(100),
GhiChu nvarchar(200)
)

insert into tblSinhVien(TenSV, NgaySinh, GioiTinh, TrinhDoHocVan, QueQuan, DiaChi, GhiChu) values
(N'Nguyễn Văn A', '2006-11-09', 1, 2, N'Thanh Hóa', N'Thanh Oai, Hà Nội, Việt Nam', N'Sinh viên năm 3 UTT lớp 75DCTT36'),
(N'Phùng Thanh Độ', '1989-09-12', 1, 3, N'Cao Bằng', N'120 Yên Lãng, Đống Đa, Hà Nội, Việt Nam', N'Cựu sinh viên cao đẳng Bách Khoa')