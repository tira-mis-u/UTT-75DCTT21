// Muốn tổng nhỏ nhất: Biến 6 thành 5. Nuốn tổng lớn nhất: Biến 5 thành 6 (vì mỗi chữ số đều được xét độc lập).
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b; cin >> a >> b;
    string mn_a = a, mn_b = b,  mx_a = a, mx_b = b;
    for(char &c : mn_a) if(c == '6') c = '5';
    for(char &c : mn_b) if(c == '6') c = '5';
    for(char &c : mx_a) if(c == '5') c = '6';
    for(char &c : mx_b) if(c == '5') c = '6';
    int mn = stoi(mn_a) + stoi(mn_b), mx = stoi(mx_a) + stoi(mx_b);
    cout << mn << ' ' << mx;
    return 0;
}
