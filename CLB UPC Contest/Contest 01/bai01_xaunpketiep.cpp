#include<bits/stdc++.h>
using namespace std;

#define fp(i,a,b) for(int i=(a);i<=(b);i++)

int a[1008],t;

void sinh(int n){
    int i=n;
    while(i>=1&&a[i]==1){
        a[i]=0;
        --i;
    }
    if(i>=1) a[i]=1;
}

int main(){
    cin>>t;
    while(t--){
        string x;cin>>x;
        int n=x.length();
        fp(i,1,n) a[i]=x[i-1]-'0';
        sinh(n);
        fp(i,1,n) cout<<a[i];
        cout<<'\n';
    }
}