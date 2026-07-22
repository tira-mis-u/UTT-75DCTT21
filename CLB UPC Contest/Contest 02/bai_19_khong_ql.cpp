/*
Đpt O(n^2) và bộ nhớ là O(n)

In-place Algorithm (Thuật toán tại chỗ): Nếu dữ liệu cũ ko dùng nữa thì ghi đè luôn
Vì giá trị cũ ko còn dùng đc ở các bước sau nên ghi đè để tiết kiệm bộ nhớ

[1, 2, 3, 4, 5]
1 + 2 = 3 -> Do số 1 khcan nữa nên ghi đè luôn: [3, 2, 3, 4, 5]
2 + 3 = 5 -> Số 2 cũng khcan nữa nên ghi đè: [3, 5, 3, 4, 5]
3 + 4 = 7 -> Số 3 khcan nữa, ghi đè luôn: [3, 5, 7, 4, 5]
4 + 5 = 9 -> Số 4 khcan, ghi đè: [3, 5, 7, 9, 5]
Vì số 5 ko cộng với số nào đằng sau nữa nên xóa phần tử cuối: [3, 5, 7, 9]
Lặp lại tương tự như thế với mảng [3, 5, 7, 9] đến khi mảng còn 1 phần tử
*/

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define fp(i, a, b) for(int i = a; i <= b; i++)

void out(vi &a){
    cout << '[';
    fp(i, 0, a.size() - 1){
        cout << a[i];
        if(i != a.size() - 1) cout << ' ';
    }
    cout << "]\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n);
        fp(i, 0, n - 1) cin >> a[i];
        while(true){
            out(a);
            if(a.size() == 1) break;
            fp(i, 0, a.size() - 2) a[i] += a[i + 1];
            a.pop_back();
        }
    }
    return 0;
}