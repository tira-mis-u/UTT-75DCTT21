#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
#define fp(i, a, b) for(int i = a; i <= b; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vi a(n + 1);
        fp(i, 1, n) cin >> a[i];
        vvb dp(n + 1, vb(s + 1));
        dp[0][0] = true;
        fp(i, 1, n) fp(j, 0, s){
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i]) dp[i][j] = dp[i][j] || dp[i - 1][j - a[i]];
        }
        cout << (dp[n][s] ? "YES" : "NO") << '\n';
    }
    return 0;
}