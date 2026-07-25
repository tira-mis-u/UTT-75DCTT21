#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define fp(i, a, b) for(int i = a; i <= b; i++)
vi a, x;
int n, k;
bool ok;

void ql(int i, int sum){
    if(sum == k){
        cout << '[';
        fp(j, 0, x.size() - 1){
            cout << x[j];
            if(j != x.size() - 1) cout << ' ';
        }
        cout << "] ";
        ok = true;
        return;
    }
    fp(j, i, n - 1){
        if(sum + a[j] <= k){
            x.push_back(a[j]);
            ql(j + 1, sum + a[j]);
            x.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        a.resize(n);
        fp(i, 0, n - 1) cin >> a[i];
        sort(a.begin(), a.end());
        x.clear();
        ok = false;
        ql(0, 0);
        if(!ok) cout << -1;
        cout << '\n';
    }
    return 0;
}
