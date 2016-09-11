#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100010;
int a[maxn];

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cout<<a[i]+a[i+1]<<" ";
    }
    cout<<a[n]<<endl;
    return 0;
}