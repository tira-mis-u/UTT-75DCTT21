/*

Đcm thề luôn cái con trỏ cấp phát động sử dụng rối não vcl
Ngồi fix vl mãi mới chạy được, toàn bị rò rỉ bộ nhớ ạ =))
Bài này đề xuất sử dụng vector ngon hơn nhiều

*/

#include<iostream>
#include<algorithm>
using namespace std;
#define endl "\n"
class DaThuc {
    protected:
        int bac;
        float *heso; // cnay tư duy nối đuôi nhau giống như linked list
    public:
        DaThuc() {
            bac = 0;
            heso = new float[1];
            heso[0] = 0;
        }
        DaThuc(int b, float *h) {
            bac = b;
            heso = new float[bac + 1]; // cấp phát động cho hệ số nhó
            for(int i = 0; i <= bac; i++) {
                heso[i] = h[i];
            }
        }
        DaThuc(const DaThuc& dt) { // Cấp phát động nên phải thêm 1 hàm copy nữa
            bac = dt.bac;
            heso = new float[bac + 1];
            for (int i = 0; i <= bac; i++)
                heso[i] = dt.heso[i];
        }
        ~DaThuc() { // hàm huỷ
            delete[] heso; // đồng thời cũng phải xoá con mẹ cnay đi (do cấp phát động)
        }
        friend istream& operator >> (istream &nhap, DaThuc &dt) {
            cout << "\nNhap bac da thuc: ";
            nhap >> dt.bac;
            delete[] dt.heso; // cnay để tránh bị leak bộ nhớ
            dt.heso = new float[dt.bac + 1];
            cout << "Hay nhap he so tu bac 0 den bac " << dt.bac << endl;
            for(int i = 0; i <= dt.bac; i++) {
                cout << "+) He so bac " << i << ": ";
                nhap >> dt.heso[i];
            }
            return nhap;
        }
        friend ostream& operator << (ostream &xuat, DaThuc &dt) {
            for(int i = 0; i <= dt.bac; i++) {
                xuat << dt.heso[i] << "x^" << i;
                if(i < dt.bac) xuat << " + ";
            }
            return xuat;
        }
        DaThuc operator + (const DaThuc& dt) {
            DaThuc kq;
            kq.bac = max(dt.bac, bac);
            delete[] kq.heso; // luôn xoá trc khi cấp phát động tránh leak memory
            kq.heso = new float[kq.bac + 1];
            for(int i = 0; i <= kq.bac; i++) {
                kq.heso[i] = 0;
                if(i <= bac) kq.heso[i] += heso[i];
                if(i <= dt.bac) kq.heso[i] += dt.heso[i];
            }
            return kq;
        }
        DaThuc operator - (const DaThuc& dt) {
            DaThuc kq;
            kq.bac = max(dt.bac, bac);
            delete[] kq.heso;
            kq.heso = new float[kq.bac + 1];
            for(int i = 0; i <= kq.bac; i++) {
                kq.heso[i] = 0;
                if(i <= bac) kq.heso[i] += heso[i]; // Kq đang là 0, thêm số A vào
                if(i <= dt.bac) kq.heso[i] -= dt.heso[i]; // Kq đang là số A, lấy A - số B
            }
            return kq;
        }
        DaThuc operator = (const DaThuc& dt) {
            if(this == &dt) return *this;
            delete[] heso; // xoá dữ liệu cũ đi
            bac = dt.bac;
            heso = new float[bac + 1];
            for(int i = 0; i <= bac; i++)
                heso[i] = dt.heso[i];
            return *this; // trả về tham chiếu
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