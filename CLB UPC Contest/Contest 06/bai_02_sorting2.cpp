#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fp(i,a,b) for(int i=a;i<=b;i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n, X; cin >> n >> X;
        vector<int> a(n);
        fp(i,0,n-1) cin >> a[i];
        stable_sort(a.begin(), a.end(), [&](int u, int v){
            return abs(X-u) < abs(X-v);
        });
        fp(i,0,n-1) cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}
