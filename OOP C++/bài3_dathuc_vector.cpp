/*

========== Chú thích thêm cho dễ hiểu về những kiểu tham số dưới đây nhó OwO ==========

[ 1 ] vector<float> hs
- Chỉ copy toàn bộ vector ko sửa đc giá trị gốc (tốn bộ nhớ vcl)
- Dùng khi chỉ cần bản sao
- (Bonus) Còn đc gọi là truyền tham trị (Pass by value): chỉ copy dữ liệu

[ 2 ] vector<float>& hs
- Truyền địa chỉ và sửa đc giá trị gốc (ko copy)
- Dùng khi cần thay đổi giá trị bên ngoài hàm
- (Bonus) Còn đc gọi là truyền tham chiếu (Pass by reference): ko copy mà sửa trực tiếp dữ liệu bên ngoài

[ 3 ] const vector<float> hs
- Ko có & tức là chỉ copy giá trị gốc (cứ copy là tốn bộ nhớ vcl)
- Có const (hằng số cố định ko sửa đc)

[ 4 ] const vector<float>& hs
- [ 2 ] + [ 3 ]: Ko cho copy cũng ko sửa, tránh tốn bộ nhớ
- Dùng khi hàm chỉ đọc dữ liệu

Tổng kết lại:
- Có '&' tức là: truyền địa chỉ, chỉnh sửa đc giá trị gốc
- Có "const" tức là: nó cố định và đ' sửa đc 😢

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"
class DaThuc {
    private:
        int bac;
        vector<float> heso;
    public:
        DaThuc() {
            bac = 0;
            heso.resize(1, 0);
        }
        DaThuc(int b, const vector<float>& hs) { 
            bac = b;
            heso = hs;
        }
        ~DaThuc(){};
        friend istream& operator >> (istream &nhap, DaThuc &dt) {
            cout << "\nNhap bac cua da thuc: ";
            nhap >> dt.bac;
            cout << "Hay nhap he so tu bac 0 den bac " << dt.bac << endl;
            dt.heso.resize(dt.bac + 1, 0);
            for(int i = 0; i <= dt.bac; i++) {
                cout << "+) He so bac " << i << ": ";
                nhap >> dt.heso[i];
            }
            return nhap;
        }
        friend ostream& operator << (ostream &xuat, DaThuc &dt) {
            for(int i = 0; i <= dt.bac; i++)
                xuat << dt.heso[i] << "x^" << i << (i < dt.bac ? " + " : "");
            return xuat;
        }
        DaThuc operator + (const DaThuc &dt) {
            DaThuc kq;
            kq.bac = max(bac, dt.bac);
            kq.heso.assign(kq.bac + 1, 0); // (kq.bac + 1) là size, 0 là giá trị mặc định cho tất cả
            for(int i = 0; i <= kq.bac; i++) {
                if(i <= bac) kq.heso[i] += heso[i];
                if(i <= dt.bac) kq.heso[i] += dt.heso[i];
            }
            return kq;
        }
        DaThuc operator - (const DaThuc &dt) {
            DaThuc kq;
            kq.bac = max(bac, dt.bac);
            kq.heso.assign(kq.bac + 1, 0);
            for(int i = 0; i <= kq.bac; i++) {
                if(i < bac) kq.heso[i] += heso[i];
                if(i < dt.bac) kq.heso[i] -= dt.heso[i];
            }
            return kq;
        }
};
int main() {
    DaThuc dt1, dt2, dt3;
    cout << "\n\n[ DA THUC DAU TIEN ]";
    cin >> dt1;
    cout << "[ DA THUC TIEP THEO ]";
    cin >> dt2;
    dt3 = dt1 + dt2;
    cout << "Cong 2 da thuc: " << dt3 << endl;
    dt3 = dt1 - dt2;
    cout << "Tru 2 da thuc: " << dt3 << endl;
    return 0;
}