#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
bool dp[1005][1005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size(), ans = 1;
        memset(dp, 0, sizeof(dp));
        fp(i, 0, n - 1) dp[i][i] = 1;
        fp(len, 2, n) fp(i, 0, n - len){
            int j = i + len - 1;
            if(s[i] != s[j]) continue;
            if(len == 2 || dp[i + 1][j - 1]){
                dp[i][j] = 1;
                ans = max(ans, len);
            }
        }
        cout << ans << '\n';
    }
}
