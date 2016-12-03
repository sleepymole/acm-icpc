#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n,m;
        cin>>n>>m;
        __float128 t=n;
        __float128 q=(t-1)/t,r=1.0;
        while(m){
            if(m&1) r=r*q;
            q=q*q;
            m>>=1;
        }
        t=1-r;
        double ans=t*n;
        printf("%.8lf\n",ans);
    }
    return 0;
}