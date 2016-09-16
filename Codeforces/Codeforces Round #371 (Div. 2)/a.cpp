#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    ll l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    if(l2>r1||r2<l1){
        cout<<0<<endl;
    }else if(l1<=l2&&r2<=r1){
        ll ans=r2-l2+1;
        if(k>=l2&&k<=r2) ans--;
        cout<<ans<<endl;
    }else if(l2<=l1&&r1<=r2){
        ll ans=r1-l1+1;
        if(k>=l1&&k<=r1) ans--;
        cout<<ans<<endl;
    }else if(r2>=r1){
        ll ans=r1-l2+1;
        if(k>=l2&&k<=r1) ans--;
        cout<<ans<<endl;
    }else{
        ll ans=r2-l1+1;
        if(k>=l1&&k<=r2) ans--;
        cout<<ans<<endl;
    }
    return 0;
}