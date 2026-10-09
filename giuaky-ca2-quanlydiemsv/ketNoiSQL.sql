create database QLDIEM_LeNguyenMinhTri
go

use QLDIEM_LeNguyenMinhTri
go

create table tblDiemSV (
ID int identity(1,1) primary key,
MaSV nvarchar(30) unique not null,
TenSV nvarchar(50) not null,
NgaySinh datetime not null,
GioiTinh int check(GioiTinh in (0,1)) not null,
DiemGiuaKy decimal(18, 0) check(DiemGiuaKy between 0 and 10) not null, -- đbiet decimal(18, 0) có ổn kh, còn thgian thì fix sau
DiemChuyenCan decimal(18, 0) check(DiemChuyenCan between 0 and 10) not null,
DiemCuoiKy decimal(18, 0) check(DiemCuoiKy between 0 and 10) not null
)
