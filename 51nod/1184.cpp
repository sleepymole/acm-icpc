#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=10000000;
const int P=510510,Q=92160;
int prime[N+1],pi[N+1],e[N/19+1];


ll Phi(ll m,ll n){
    if(n==0) return m;
    if(n==7) return m/P*Q+e[m%P];
    if(m<prime[n]) return 1;
    return Phi(m,n-1)-Phi(m/prime[n],n-1);
}

ll Pi(ll m){
    if(m<=N) return pi[m];
    int y=int(pow(m,1.0/3))+1,n=pi[y];
    ll ans=Phi(m,n)+n-1;
    for(ll p=y+1;p*p<=m;p++){
        if(pi[p]==pi[p-1]) continue;
        ans-=Pi(m/p)-Pi(p)+1;
    }
    return ans;
}

ll f[N/3*2+1];
ll calc(ll n){
    if(n<=prime[0]) return prime[n];
    ll x=n*(log(n)+log(log(n))-1)+n*(log(log(n))-2)/log(n);
    ll y=n*(log(log(n)))*(log(log(n)))/log(n)/log(n);
    y=min(y,ll(3e6));
    ll l=x-y,r=x+y;
    ll count=Pi(l-1);
    for(int i=1;i<=prime[0];i++){
        if(prime[i]>r/prime[i]) break;
        for(ll j=((l-1)/prime[i]+1)*prime[i];j<=r;j+=prime[i]){
            f[j-l]=1;
            
        }
    }
    for(ll i=l;i<=r;i++){
        if(!f[i-l]){
            count++;
            if(count==n) return i;
        }
    }
    return -1;
}

int main(){
    for(int i=2;i<=N;i++){
        if(!prime[i]) prime[++prime[0]]=i,pi[i]=pi[i-1]+1;
        else pi[i]=pi[i-1];
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1; if(i%prime[j]==0) break;
        }
    }
    for(int i=0;i<P;i++) e[i]=i;
    for(int i=1;i<=7;i++){
        for(int j=P-1;j>=0;j--){
            e[j]-=e[j/prime[i]];
        }
    }
    ll n;
    cin>>n;
    cout<<calc(n)<<endl;
    return 0;
}