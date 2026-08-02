#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int n, k;
vector<int> a;
void ktao(){
    a.assign(n + 1, 0);
}
bool sinh(){
    int i = n;
    while(i && a[i]){
        a[i] = 0;
        i--;
    }
    if(!i) return false;
    a[i] = 1;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        ktao();
        do {
            int cnt = 0;
            fp(i, 1, n) cnt += a[i];
            if(cnt == k){
                fp(i, 1, n) cout << a[i];
                cout << '\n';
            }
        } while(sinh());
    }
}
