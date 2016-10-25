#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef __int128 int128;
const int mod=1000000007;
const double a=0.6942419136306174;
const double b=1.160964047443681;
const int N=100;
int128 f[N+1],s[N+1];

int main(){
    f[0]=0;f[1]=1;
    for(int i=2;i<=N;i++){
        f[i]=f[i-1]+f[i-2];
    }
    s[0]=f[0];
    for(int i=1;i<=N;i++){
        s[i]=s[i-1]|f[i];
    }
    int T;
    scanf("%d",&T);
    while(T--){
        ll n;
        scanf("%lld",&n);
        if(n<=N){
            printf("%d\n",int(s[n]%mod));
            continue;
        }
        ll k=ll(a*n-b)+1;
        int ans=1,base=2;
        while(k){
            if(k%2) ans=(ll)ans*base%mod;
            base=(ll)base*base%mod;
            k/=2;
        }
        ans=(ans+mod-1)%mod;
        printf("%d\n",ans);
    }
    return 0;
}