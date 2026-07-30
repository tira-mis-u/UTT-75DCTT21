#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fp(i,a,b) for(int i=a;i<=b;i++)
ll dnc(ll n, ll k){
    if(n == 1) return 1;
    ll mid = 1LL << (n - 1); // 2^(n-1)  1LL để tránh tràn bit khi dịch trái
    if(k == mid) return n;
    if(k < mid) return dnc(n - 1, k);
    return dnc(n - 1, k - mid);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        ll n, k; cin >> n >> k;
        cout << dnc(n, k) << '\n';
    }
    return 0;
}
