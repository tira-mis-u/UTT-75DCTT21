// Đpt và bộ nhớ đều là O(n^2)

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
#define fp(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
vvi ans;

void ql(vi a){
    ans.pb(a);
    if(a.size() == 1) return;
    vi b;
    fp(i, 0, a.size() - 2) b.pb(a[i] + a[i + 1]);
    ql(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n);
        fp(i, 0, n - 1) cin >> a[i];
        ans.clear();
        ql(a);
        for(vi x : ans){
            cout << '[';
            fp(i, 0, x.size() - 1){
                cout << x[i];
                if(i != x.size() - 1) cout << ' ';
            }
            cout << "]\n";
        }
    }
    return 0;
}