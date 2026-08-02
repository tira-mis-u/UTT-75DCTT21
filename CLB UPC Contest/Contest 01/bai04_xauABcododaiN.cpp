#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int n;
vector<char> s;
void ktao(){
    s.assign(n + 1, 'A');
}
bool sinh(){
    int i = n;
    while(i && s[i] == 'B') i--;
    if(!i) return false;
    s[i] = 'B';
    fp(j, i + 1, n) s[j] = 'A';
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n;
        ktao();
        do {
            fp(i, 1, n) cout << s[i];
            cout << ' ';
        } while(sinh());
        cout << '\n';
    }
}
