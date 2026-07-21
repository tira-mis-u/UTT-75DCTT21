#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define fp(i, a, b) for(int i = a; i <= b; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vi a(n + 1), dp(n + 1, 1);
    fp(i, 1, n) cin >> a[i];
    int ans = 1;
    fp(i, 1, n){
        fp(j, 1, i - 1) if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}