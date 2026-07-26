// Sxep chữ số tăng dần, đưa từng chữ số vào số đang có ít chữ số hơn để các chữ số nhỏ nằm ở hàng giá trị lớn & 2 số có độ dài cân bằng => tổng là nhỏ nhất

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n);
        fp(i, 0, n - 1) cin >> a[i];
        sort(a.begin(), a.end());
        long long x = 0, y = 0;
        fp(i, 0, n - 1){
            if(i % 2 == 0) x = x * 10 + a[i];
            else y = y * 10 + a[i];
        }
        cout << x + y << '\n';
    }
    return 0;
}
