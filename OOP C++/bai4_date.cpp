#include<iostream>
#include<string>
using namespace std;
class Date {
    private:
        int ngay, thang, nam;
        string addZero(int val, int size) {
            string s = to_string(val);
            while(s.length() < size)
                s = "0" + s;
            return s;
        }
        void calcDate(int &a, int &b, int &c) {
            if(a > b) { // Nếu ngày/tháng vượt quá max
                a = 1; // Thì chuyển về ngày/tháng đầu của tháng/năm mới
                c++; // Chuyển mẹ sáng tháng/năm mới
            }
            if(a <= 0) {
                a = b;
                c--;
            }
        }
    public:
        Date() {
            ngay = 0, thang = 0, nam = 0;
        }
        Date(int d, int m, int y) {
            ngay = d, thang = m, nam = y;
        }
        ~Date(){};
        friend istream& operator >> (istream& nhap, Date& d) {
            do {
                cout << "\nNhap lan luot ngay, thang, nam: ";
                nhap >> d.ngay >> d.thang >> d.nam;
            } while(d.ngay <= 0 || d.ngay > 31 || d.thang <= 0 || d.thang > 12 || d.nam <= 0);
            return nhap;
        }
        friend ostream& operator << (ostream& xuat, Date& d) {
            xuat << d.addZero(d.ngay, 2) << "-" << d.addZero(d.thang, 2) << "-" << d.addZero(d.nam, 4);
            return xuat;
        }
        void chuanHoa() {
            int maxMonth = 12;
            int thang2 = (nam % 4 == 0 ? 29 : 28);
            int maxDay[maxMonth] = {31, thang2, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            calcDate(ngay, maxDay[thang - 1], thang);
            calcDate(thang, maxMonth, nam);
        }
        Date operator ++ () {
            ngay++;
            chuanHoa();
            return *this;
        }
        Date operator -- () {
            ngay--;
            chuanHoa();
            return *this;
        }

};
int main(){
    cout << "Nhap so luong thoi gian ban muon tao: ";
    int n; cin >> n;
    Date *d = new Date[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        cout << "Thoi gian hien tai: " << d[i] << endl;
        Date d1 = d[i], d2 = d[i];
        ++d1;
        cout << "Tang them 1 ngay: " << d1 << endl;
        --d2;
        cout << "Giam di 1 ngay: " << d2 << endl;
    }
    return 0;
}