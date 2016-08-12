#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;

int main(){
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        double p,q;
        int k1,k2;
        cin>>q>>k1>>k2;
        p=1.0-q;
        double ans;
        if(q<eps) ans=k1;
        else if(1-q<eps) ans=k2;
        else{
            double a=(1.0-pow(p,k1))*(1.0-pow(q,k2));
            ans=a/(1.0-a-pow(p,k1+1)-pow(q,k2+1));
           // ans=1.0/(p/(1-pow(q,k2))+q/(1-pow(p,k1))-1);
        }
        printf("Case %d: %lf\n", ca,ans);
    }
    return 0;
}