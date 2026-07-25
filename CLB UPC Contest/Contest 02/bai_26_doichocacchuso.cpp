#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
string s, ans;
int k, n;

void ql(int i, int k){
    if(s > ans) ans = s;
    if(i == n || k == 0) return;
    char mx = s[i];
    fp(j, i + 1, n - 1) mx = max(mx, s[j]);
    if(mx == s[i]){
        ql(i + 1, k);
        return;
    }
    fp(j, i + 1, n - 1){
        if(s[j] == mx){
            swap(s[i], s[j]);
            ql(i + 1, k - 1);
            swap(s[i], s[j]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> k >> s;
        n = s.size();
        ans = s;
        ql(0, k);
        cout << ans << '\n';
    }
    return 0;
}
