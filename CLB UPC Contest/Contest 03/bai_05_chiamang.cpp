/* Muốn hiệu hai mảng lớn nhất thì cho mảng ít phần tử hơn chứa toàn các số nhỏ nhất, để mảng còn lại giữ các số lớn nhất
Mục tiêu:
- Làm cho hiệu tổng của hai mảng lớn nhất
Chọn:
- Cho mảng ít phần tử hơn nhận các số nhỏ nhất để tổng của nó nhỏ nhất
Có phải đổi lại sau không?
- Không, vì đổi số nhỏ thành số lớn chỉ làm tổng mảng nhỏ tăng lên, hiệu giảm đi
Vì sao quyết định đó luôn tối ưu?
- Vì nếu mảng nhỏ còn chứa số lớn trong khi mảng lớn có số nhỏ hơn thì chỉ cần đổi chỗ là hiệu sẽ tăng, nên nghiệm tối ưu bắt buộc mảng nhỏ phải chứa toàn số nhỏ nhất
*/
#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n, k, sum = 0; cin >> n >> k;
        vector<int> a(n);
        fp(i, 0, n - 1){
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        k = min(k, n - k);
        int s = 0;
        fp(i, 0, k - 1) s += a[i];
        cout << sum - 2 * s << '\n';
    }
}
