#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
#define rt return
int tknp(vector<int> &a, int l, int r, int k){
    if(l > r) rt -1;
    int mid = (l + r) / 2;
    if(a[mid] == k) rt mid;
    if(a[mid] < k) rt tknp(a, mid + 1, r, k);
    rt tknp(a, l, mid - 1, k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        fp(i, 1, n) cin >> a[i];
        int ans = tknp(a, 1, n, k);
        if(ans == -1) cout << "NO\n";
        else cout << ans << '\n';
    }
    rt 0;
}
