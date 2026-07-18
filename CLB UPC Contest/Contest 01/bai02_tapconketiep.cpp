#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(int i=(a);i<=(b);i++)

int a[1008],t;
void sinh(int n, int k){
    int i=k;
    while(i>=1&&a[i]==n-k+i) --i;
    if(i>=1){
        a[i]++;
        fp(j,i+1,k) a[j]=a[j-1]+1;
    }else{
        fp(j,1,k) a[j]=j;
    }
}
int main() {
    cin >> t;
    while(t--){
        int n,k; cin>>n>>k;
        fp(i,1,k) cin>>a[i];
        sinh(n,k);
        fp(i,1,k) cout<<a[i]<<' ';
        cout<<'\n';
    }
}