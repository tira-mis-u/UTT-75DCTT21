#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
using ll = long long;
const int MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> dp(n + 1);
        dp[0] = 1;
        fp(i, 1, n) fp(j, 1, min(i, k))
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        cout << dp[n] << '\n';
    }
}
