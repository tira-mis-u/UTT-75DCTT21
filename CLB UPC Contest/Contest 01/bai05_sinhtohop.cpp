// Mỗi lần tìm phần tử bên phải nhất còn tăng được, tăng nó lên 1 rồi đưa các phần tử phía sau về GTNN có thể để tạo tổ hợp kế tiếp
#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int n, k;
vector<int> a;
void ktao(){
    a.assign(k + 1, 0);
    fp(i, 1, k) a[i] = i;
}
bool sinh(){
    int i = k;
    while(i && a[i] == n - k + i) i--;
    if(!i) return false;
    a[i]++;
    fp(j, i + 1, k)
        a[j] = a[j - 1] + 1;
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
            fp(i, 1, k) cout << a[i];
            cout << ' ';
        } while(sinh());
        cout << '\n';
    }
}
