#include <bits/stdc++.h>
using namespace std;

int t, a[1008];

void sinh(int n) {
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        --i;
    }
    if (i >= 1) a[i] = 1;
}

int main() {
    cin >> t;
    while (t--) {
        string x; cin >> x;
        int n = x.length();
        for(int i = 1; i <= n; i++) a[i] = x[i - 1] - '0';
        sinh(n);
        for(int i = 1; i <= n; i++) cout << a[i];
        cout << '\n';
    }
}