#include<bits/stdc++.h>
using namespace std;

// Độ phức tạp O(n)
long long fibo(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else if(n > 1) return fibo(n - 1) + fibo(n - 2);
    else return -1;
}

// Test chương trình:
int main() {
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << fibo(n) << "\n";
    }
    return 0;
}