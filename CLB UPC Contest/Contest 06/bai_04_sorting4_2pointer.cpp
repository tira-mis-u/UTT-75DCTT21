#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fp(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m), uni, inter;
        fp(i,0,n-1) cin >> a[i];
        fp(i,0,m-1) cin >> b[i];
        int i = 0, j = 0;
        while(i<n && j<m){
            if(a[i]<b[j]) uni.pb(a[i++]);
            else if(a[i]>b[j]) uni.pb(b[j++]);
            else {
                uni.pb(a[i]);
                inter.pb(a[i]);
                i++; j++;
            }
        }
        while(i<n) uni.pb(a[i++]);
        while(j<m) uni.pb(b[j++]);
        for(int x: uni) cout << x << ' ';
        cout << '\n';
        for(int x: inter) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
