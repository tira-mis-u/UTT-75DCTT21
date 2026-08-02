/*
Thuật toán sinh phân hoạch số nguyên (Integer Partition Generation)
Mỗi lần giảm phần tử khác 1 gần cuối nhất đi 1, rồi gom các số 1 phía sau để phân chia lại thành các phần tử lớn nhất có thể nhằm tạo ra phân hoạch kế tiếp
*/

#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int n, cnt;
vector<int> a;
void ktao(){
    cnt = 1;
    a.assign(n + 1, 0);
    a[1] = n;
}
bool sinh(){
    int i = cnt;
    while(i && a[i] == 1) i--;
    if(!i) return false;
    a[i]--;
    int d = cnt - i + 1;
    cnt = i;
    while(d > a[i]){
        a[++cnt] = a[i];
        d -= a[i];
    }
    a[++cnt] = d;
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
            cout << '(';
            fp(i, 1, cnt){
                cout << a[i];
                if(i != cnt) cout << ' ';
            }
            cout << ") ";
        } while(sinh());
        cout << '\n';
    }
}
