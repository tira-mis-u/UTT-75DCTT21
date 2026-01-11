#include<iostream>
#include<string.h>
using namespace std;
class Time{
    private:
        int gio, phut, giay;
        string addZero(int val) {
            return (val < 10 ? "0" : "") + to_string(val);
        }
        void calcTime(int &a, int &b, int &c) {
            while(a >= b) { // Nếu giờ/phút/giây vượt quá max
                if(a > b) a = b - 1; // Chuyển về 23h hoặc 59p, 59s
                c++; // Tăng phút/giây/giờ lên 1 đơn vị
                if(a == b) a = 0; // Nếu là 24h thì chuyển về 0h
            }
            while(a < 0) {
                a = b - 1;
                c--;
            }
        }
    public:
        friend istream& operator >> (istream& nhap, Time& t) {
            do {
                cout << "\nNhap lan luot gio, phut, giay: ";
                nhap >> t.gio >> t.phut >> t.giay;
            } while(t.gio < 0 || t.gio >= 24 || t.phut < 0 || t.phut >= 60 || t.giay < 0 || t.giay >= 60);
            return nhap;
        }
        friend ostream& operator << (ostream& xuat, Time& t) {
            xuat << t.addZero(t.gio) << ":" << t.addZero(t.phut) << ":" << t.addZero(t.giay);
            return xuat;
        }
        void chuanHoa() {
            int maxHours = 24, maxTime = 60;
            calcTime(giay, maxTime, phut);
            calcTime(phut, maxTime, gio);
            calcTime(gio, maxHours, giay);
        }
        Time operator ++ () {
            giay++;
            chuanHoa();
            return *this;
        }
        Time operator -- () {
            giay--;
            chuanHoa();
            return *this;
        }
};
int main() {
    cout << "Nhap so luong thoi gian ban muon tao: ";
    int n; cin >> n;
    Time *t = new Time[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        cout << "Thoi gian hien tai: " << t[i] << endl;
        Time t1 = t[i], t2 = t[i];
        ++t1;
        cout << "Tang them 1 giay: " << t1 << endl;
        --t2;
        cout << "Giam di 1 giay: " << t2 << endl;
    }
    return 0;
}