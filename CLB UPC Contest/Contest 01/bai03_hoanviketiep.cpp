#include<bits/stdc++.h>
using namespace std;
#define fp(i,a,b) for(int i=(a);i<=(b);i++)
int a[1008],t;
void sinh(int n){
    int i=n-1;
    while(i>=1&&a[i]>a[i+1]) --i;
    if(i==0){
        fp(j,1,n) a[j]=j;
    }else{
        int k=n;
        while(a[k]<a[i]) --k;
        swap(a[i],a[k]);
        reverse(a+i+1,a+n+1);
    }
}
int main(){
    cin>>t;
    while(t--){
        int n;cin>>n;
        fp(i,1,n) cin>>a[i];
        sinh(n);
        fp(i,1,n) cout<<a[i]<<' ';
        cout<<'\n';
    }
}