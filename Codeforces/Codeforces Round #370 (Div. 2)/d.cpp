#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int mod=1000000007;

int inverse(int a){
    return a==1?1:(ll)inverse(mod%a)*(mod-mod/a)%mod;
}
int Combination(int n,int m){
    if(n<m) return 0;
    ll res=1,s=1;
    for(int i=0;i<m;i++){
        res=res*(n-i)%mod;
        s=s*(i+1)%mod;
    }
    return res*inverse(s)%mod;
}

int power_mod(int a,int n){
    int r=1;
    while(n){
        if(n%2) r=(ll)r*a%mod;
        a=(ll)a*a%mod;
        n/=2;
    }
    return r;
}

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int a,b,k,t,r,s,m;
    cin>>a>>b>>k>>t;
    r=2*k;s=2*t*k+b-a;
    m=2*t;
    ll ans=0;
    for(int i=0;i<=m;i++){
        int n=s-(r+1)*i;
        if(n<0) continue;
        if(i%2==0){
            ans=(ans+(ll)Combination(m,i)*Combination(n+m,m)%mod)%mod;
        }else{
            ans=(ans-(ll)Combination(m,i)*Combination(n+m,m)%mod)%mod;
        }
    }
    ans=power_mod(r+1,m)-ans;
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
    return 0;
}