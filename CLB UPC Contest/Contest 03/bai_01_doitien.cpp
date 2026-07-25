// Mỗi lần cứ lấy tờ tiền có giá trị lớn nhất mà số tiền còn lại vẫn đủ trả, để dùng càng ít tờ tiền càng tốt.

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define fp(i, a, b) for(int i = a; i <= b; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi a = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int t; cin >> t;
    while(t--){
        int n, ans = 0; cin >> n;
        for(int i = a.size() - 1; i >= 0; i--){
            ans += n / a[i];
            n %= a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
