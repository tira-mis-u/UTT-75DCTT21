// Đpt: O(log k), bộ nhớ: O(n)
// Mỗi lần chia đôi số mũ, nếu bit cuối của số mũ là 1 thì nhân vào đáp án, đồng thời bình phương cơ số để chuẩn bị cho lần chia tiếp theo
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll powMod(ll n, ll k){
    ll ans = 1;
    while(k){ // tư duy đổi số mũ (hệ 10) sang hệ 2
        if(k % 2) ans = ans * n % mod;
        n = n * n % mod; // bphuong ltuc (như kiểu tờ giấy gấp đôi heh) -> Xét lũy thừa kế tiếp: (n^x)² = n^{2x}
        k /= 2; // xét bit tiếp theo của số mũ
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        cout << powMod(n, k) << '\n';
    }
    return 0;
}
