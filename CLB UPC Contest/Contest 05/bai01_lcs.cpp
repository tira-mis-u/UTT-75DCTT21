#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define fp(i, a, b) for(int i = a; i <= b; i++)

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        vvi dp(n + 1, vi(m + 1, 0));
        fp(i, 1, n) fp(j, 1, m){
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
        cout << dp[n][m] << '\n';
    }
    return 0;
}