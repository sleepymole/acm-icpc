#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

ll find(ll n,ll k){
    if(k<(1LL<<(n-1))) return find(n-1,k);
    else if(k>(1LL<<(n-1))) return find(n-1,k-(1LL<<(n-1)));
    return n;
}
int main(){
    long long n,k;
    cin>>n>>k;
    cout<<find(n,k)<<endl;
    return 0;
}