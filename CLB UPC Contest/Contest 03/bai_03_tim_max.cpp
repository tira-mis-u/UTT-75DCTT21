// Muốn tổng max, xếp các số max vào những vị trí có hệ số i max
// Sxep mảng tăng dần rồi nhân lần lượt 0 -> n - 1
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define fp(i, a, b) for(int i = a; i <= b; i++)
const long long mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n);
        fp(i, 0, n - 1) cin >> a[i];
        sort(a.begin(), a.end());
        long long ans = 0;
        fp(i, 0, n - 1) ans = (ans + 1LL * a[i] * i) % mod;
        cout << ans << '\n';
    }
    return 0;
}
