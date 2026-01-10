#include<bits/stdc++.h>
using namespace std;

// Chuyển đĩa từ cọc A sang cọc B với cọc C là trung gian
void hanoiTower(int n, char a, char b, char c) {
    if(n == 1) {
        cout << "Chuyen dia tu coc " << a << " sang coc " << b << "\n";
        return;
    }
    hanoiTower(n - 1, a, c, b); // Chuyển từ A -> C
    hanoiTower(1, a, b, c); // Chuyển từ A -> B
    hanoiTower(n - 1, c, b, a); // Chuyển từ C -> B
}

int main() {
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
    #endif
    int n; cin >> n;
    hanoiTower(n, 'A', 'B', 'C');
    return 0;
}