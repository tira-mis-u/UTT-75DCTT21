// Đpt O(n logn) do phải sxep (sort)
// Greedy: Sau khi sxep, mỗi lần lấy số lớn nhất còn lại rồi lấy số nhỏ nhất còn lại để tạo ngay kết quả cuối cùng.
#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n + 1);
        fp(i, 1, n) cin >> a[i];
        sort(a.begin() + 1, a.end());
        int l = 1, r = n;
        while(l <= r){
            cout << a[r--] << ' '; // Greedy
            if(l <= r) cout << a[l++] << ' '; // Greedy
        }
        cout << '\n';
    }
    return 0;
}
