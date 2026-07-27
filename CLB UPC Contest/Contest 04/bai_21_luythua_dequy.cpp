// Đpt và bộ nhớ O(log k)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll powMod(ll n, ll k){
    if(k == 0) return 1;
    ll x = powMod(n, k / 2);
    x = x * x % mod;
    if(k % 2) x = x * n % mod;
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        cout << powMod(n, k) << '\n';
    }
    return 0;
}
