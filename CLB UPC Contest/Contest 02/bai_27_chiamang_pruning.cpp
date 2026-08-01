// Bài này fckin hard

#include <bits/stdc++.h>
using namespace std;
#define fp(i, a, b) for(int i = a; i <= b; i++)
#define rt return
int n, k, target;
vector<int> a;
vector<bool> used;
bool ok;
void ql(int cur, int sum, int pos){
    if(ok) rt;
    if(cur == k){
        ok = true;
        rt;
    }
    if(sum == target){
        ql(cur + 1, 0, 1);
        rt;
    }
    int pre = -1;
    fp(i, pos, n){
        if(used[i]) continue;
        if(sum + a[i] > target) continue; // Vượt tổng thì cắt tỉa
        if(a[i] == pre) continue; // nếu giá trị tiếp theo giống hệt thì bỏ qua để tránh duyệt hai nhánh tương đương
        used[i] = true;
        ql(cur, sum + a[i], i + 1);
        used[i] = false;
        pre = a[i];
        if(ok) rt; // có đáp án thì dừng hết đệ quy
        if(sum == 0) rt; // cắt tỉa mạnh nhất: Nếu ngay cả việc bắt đầu một tập mới bằng phần tử lớn nhất còn lại cũng thất bại, thì đổi sang phần tử đầu tiên khác chỉ tạo ra các cách chia tương đương, nên không cần thử nữa.
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        a.assign(n + 1, 0);
        used.assign(n + 1, false);
        int s = 0;
        fp(i, 1, n){
            cin >> a[i];
            s += a[i];
        }
        if(s % k){
            cout << 0 << '\n';
            continue;
        }
        target = s / k;
        ok = false;
        sort(a.begin() + 1, a.end(), greater<int>()); // sxep giảm dần để loại nhánh sớm
        if(a[1] > target){ // phần tử lớn vượt target thì ko chia đc
            cout << 0 << '\n';
            continue;
        }
        ql(1, 0, 1);
        cout << ok << '\n';
    }
    rt 0;
}
