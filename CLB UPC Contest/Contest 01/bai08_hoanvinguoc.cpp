// Bắt đầu từ hoán vị lớn nhất, mỗi lần tìm cặp đầu tiên từ phải sang trái còn giảm được, đổi với số nhỏ hơn gần nhất bên phải rồi đảo ngược đoạn phía sau để thu được hoán vị liền trước
#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int n;
vector<int> a;
void ktao(){
    a.assign(n + 1, 0);
    fp(i, 1, n) a[i] = n - i + 1;
}
bool sinh(){
    int i = n - 1;
    while(i && a[i] < a[i + 1]) i--;
    if(!i) return false;
    int j = n;
    while(a[j] > a[i]) j--;
    swap(a[i], a[j]);
    reverse(a.begin() + i + 1, a.end());
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
            fp(i, 1, n) cout << a[i];
            cout << ' ';
        } while(sinh());
        cout << '\n';
    }
}
