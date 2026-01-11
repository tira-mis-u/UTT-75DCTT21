#include<iostream>
#include<cmath>
using namespace std;
#define endl "\n"
class ps1{
    protected:
        int tuso, mauso;
        int gcd(int a, int b) {
            if(b == 0) return a;
            return gcd(b, a % b);
        }
    public:
        ps1() {
            tuso = 0;
            mauso = 1;
        }
        ps1(int t, int m) {
            tuso = t;
            mauso = m;
        }
        ~ps1(){};
        friend istream& operator >> (istream &nhap, ps1 &p){
            cout << "\nNhap lan luot tu so va mau so: ";
            nhap >> p.tuso >> p.mauso;
            return nhap;
        }
        friend ostream& operator << (ostream &xuat, ps1 &p) {
            xuat <<  p.tuso << "/" << p.mauso;
            return xuat;
        }
        void rutgon() {
            int uoc = gcd(tuso, mauso);
            tuso /= uoc;
            mauso /= uoc;
        }
};
class ps2 : public ps1 { // Đề bảo kế thừa clm đù ngê
    public:
        ps2 operator = (const ps2 &p) {
            if(this != &p) { // nếu địa chỉ của class này khác địa chỉ của class p thì g
                tuso = p.tuso;
                mauso = p.mauso;
            }
            return *this; // this là địa chỉ của class, *this là giá trị của class
        }
        bool operator < (ps2 &p){
            return tuso * p.mauso < p.tuso * mauso;
        }
        bool operator > (ps2 &p){
            return tuso * p.mauso > p.tuso * mauso;
        }
};
int main() {
    int n;
    cout << "Nhap so phan so can tao: ";
    cin >> n;
    ps2 *p = new ps2[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i].rutgon(); // kh muốn rút gọn thì bỏ mẹ dòng này nhó
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i] > p[j]) {
                swap(p[i], p[j]);
            }
        }
    }
    cout << "Phan so nho nhat la: " << p[0] << endl;
    cout << "Phan so lon nhat la: " << p[n - 1] << endl;
    delete[] p;
    return 0;
}