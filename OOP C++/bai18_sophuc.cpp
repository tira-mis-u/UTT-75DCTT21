#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
class SP1 {
    private:
        float thuc, ao;
    public:
        SP1(){
            thuc = 0, ao = 0;
        }
        SP1(float re, float im){
            thuc = re, ao = im;
        }
        ~SP1(){};
        friend istream& operator >> (istream& nhap, SP1& sp) {
            cout << "Nhap lan luot phan thuc va phan ao: ";
            nhap >> sp.thuc >> sp.ao;
            return nhap;
        }
        friend ostream& operator << (ostream& xuat, SP1& sp) {
            xuat << sp.thuc << (sp.ao >= 0 ? "+" : "") << sp.ao << "i";
            return xuat;
        }
        SP1& operator = (const SP1& sp) { // '&' trước operator dùng khi ko tạo object mới (chỉ return object này)
            if(this == &sp) return *this;
            ao = sp.ao, thuc = sp.thuc;
            return *this;
        }
        SP1 operator + (const SP1& sp) {
            SP1 kq;
            kq.ao = sp.ao + ao;
            kq.thuc = sp.thuc + thuc;
            return kq;
        }
        SP1 operator - (const SP1& sp) {
            SP1 kq;
            kq.ao = ao - sp.ao;
            kq.thuc = thuc - sp.thuc;
            return kq;
        }
        SP1 operator * (const SP1& sp) {
            SP1 kq;
            kq.ao = thuc * sp.ao + ao * sp.thuc;
            kq.thuc = thuc * sp.thuc - ao * sp.ao;
            return kq;
        }
        SP1 operator / (const SP1& sp) { // Hàm này lười quá tra chatgpt cho nhanh
            float m = sp.thuc * sp.thuc + sp.ao * sp.ao;
            return SP1(
                (thuc * sp.thuc + ao * sp.ao) / m,
                (ao * sp.thuc - thuc * sp.ao) / m
            );
        }
        bool operator == (const SP1& sp) {
            return (ao == sp.ao && thuc == sp.thuc);
        }
        float modul() const { // Hàm nào bên trong ko sửa object thì dùng const phía sau
            return sqrt(ao * ao + thuc * thuc);
        }
        bool operator > (const SP1& sp) const {
            return modul() > sp.modul();
        }
        bool operator < (const SP1& sp) const {
            return modul() < sp.modul();
        }
};
class SP2 {
    private:
        int n;
        SP1 *sp;
    public:
    void nhap() {
        do{
            cout << "Nhap so luong so phuc (toi da 10): ";
            cin >> n;
        } while(n > 10);
        sp = new SP1[n + 1];
        for(int i = 0; i < n; i++) {
            cin >> sp[i];
        }
    }
    int dem(SP1& sp0) {
        int cnt = 0;
        for(int i = 0; i < n; i++) if(sp0 == sp[i]) cnt++;
        return cnt;
    }
    void exchangeSort() { // Sxep theo thứ tự giảm dần
        for(int i = 0; i < n - 1; i++) for(int j = i + 1; j < n; j++)
            if(sp[i] < sp[j]) swap(sp[i], sp[j]);
    }
    void xuat() {
        exchangeSort();
        SP1 sum, r34 = SP1(3, 4);
        cout << "Sap xep so phuc theo thu tu giam dan cua module: " << endl;
        for(int i = 0; i < n; i++) {
            cout << sp[i] << " ";
            sum = sum + sp[i];
        }
        cout << "So phuc co module lon nhat la: " << sp[0] << endl;
        cout << "So phuc co module nho nhat la: " << sp[n - 1] << endl;
        cout << "Tong so phuc trong day so la: " << sum << endl;
        cout << "So luong so phuc co gia tri " << r34 << " la: " << dem(r34) << endl;
    }
};
int main() {
    SP2 sp;
    sp.nhap();
    sp.xuat();
    return 0;
}