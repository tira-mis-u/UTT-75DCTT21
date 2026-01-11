#include<iostream>
#include<cmath> // Thư viện chuẩn của C++, còn math.h là của C 🤞❤❤❤
#include<string> // Tất cả chỉ để lưu tên loại tam giác 😢
using namespace std;
class Point {
    private:
        float x, y;
    public:
        Point() {
            x = 0, y = 0;
        }
        Point(float hd, float td) {
            x = hd, y = td;
        }
        ~Point(){};
        friend istream& operator >> (istream& nhap, Point& p) {
            cout << "> Nhap lan luot toa do x, y: ";
            nhap >> p.x >> p.y;
            return nhap;
        }
        friend ostream& operator << (ostream& xuat, Point& p) {
            xuat << "(" << p.x << "; " << p.y << ")";
            return xuat;
        }
        friend float khoangcach(Point a, Point b) {
            return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
        }
};
class TamGiac {
    private:
        Point a, b, c;
        float ab, bc, ac;
        bool pytago(float c1, float c2, float c3) {
            return (c1 * c1 + c2 * c2 == c3 * c3);
        }
        bool isTriangle(float c1, float c2, float c3) {
            return (c1 + c2 > c3 && c1 + c3 > c2 && c2 + c3 > c1);
        }
        // bool equal(float a, float b) {
        //     return abs(a - b) < 1e-6;
        // }
    public:
        TamGiac() {
            ab = bc = ac = 0;
        }
        void nhap() {
            cout << "\nNhap diem A:\n"; cin >> a;
            cout << "Nhap diem B:\n"; cin >> b;
            cout << "Nhap diem C:\n"; cin >> c;
            ab = khoangcach(a, b);
            bc = khoangcach(b, c);
            ac = khoangcach(a, c);
        }
        void xuat() {
            cout << "Toa do 3 dinh lan luot la: A" << a << ", B" << b << ", C" << c << endl;
        }
        void checkTamGiac() {
            if(!isTriangle(ab, bc, ac)) {
                cout << "\n3 dinh ko tao thanh tam giac";
                return;
            }
            bool can = ab == bc || bc == ac || ab == ac; // 2 cạnh bằng nhau
            bool deu = ab == bc && bc == ac; // 3 cạnh bằng nhau
            bool vuong = pytago(ab, bc, ac) || pytago(ab, ac, bc) || pytago(ac, bc, ab);
            string tentamgiac = "thuong";
            if(can) tentamgiac = "can";
            else if(deu) tentamgiac = "deu";
            else if(vuong) tentamgiac = "vuong";
            else if(vuong && can) tentamgiac = "vuong can";
            cout << "3 dinh tao thanh tam giac " << tentamgiac;
        }
};
int main() {
    cout << "Nhap so luong tam giac can tao: ";
    int n; cin >> n;
    TamGiac *tg = new TamGiac[n + 1];
    for(int i = 0; i < n; i++) {
        tg[i].nhap();
        tg[i].xuat();
        tg[i].checkTamGiac();
    }
    delete[] tg;
    return 0;
}