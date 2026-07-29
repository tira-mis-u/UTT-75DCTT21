#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fp(i,a,b) for(int i=a;i<=b;i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        queue<int> q;
        while(n--){
            int t; cin >> t;
            switch(t){
                case 1:
                    cout << q.size() << '\n';
                    break;
                case 2:
                    cout << (q.empty() ? "YES" : "NO") << '\n';
                    break;
                case 3:{
                    int x;
                    cin >> x;
                    q.push(x);
                    break;
                }
                case 4:
                    if(!q.empty()) q.pop();
                    break;
                case 5:
                    cout << (q.empty() ? -1 : q.front()) << '\n';
                    break;
                case 6:
                    cout << (q.empty() ? -1 : q.back()) << '\n';
                    break;
            }
        }
    }

    return 0;
}
