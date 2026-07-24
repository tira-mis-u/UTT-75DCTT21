#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
string s;
bool used[15];
void ql(string t){
    if(t.size() == s.size()){
        cout << t << ' ';
        return;
    }
    fp(i, 0, s.size() - 1){
        if(!used[i]){
            used[i] = true;
            ql(t + s[i]);
            used[i] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> s;
        memset(used, false, sizeof(used));
        ql("");
        cout << '\n';
    }
    return 0;
}
