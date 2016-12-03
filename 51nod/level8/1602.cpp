#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int N=50000000;
const ll INF=10000000000LL;
int mu[N+1];
ll Mu[N+1];

int prime[N+1];
void Sieve(){
    Mu[1]=mu[1]=1;
    for(int i=2;i<=N;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }else{
                mu[i*prime[j]]=-mu[i];
            }
        }
        Mu[i]=Mu[i-1]+mu[i];
    }
}

unordered_map<ll,ll>Hash;
ll calcMu(ll n){
    if(n<=N) return Mu[n];
    if(Hash.count(n)) return Hash[n];
    ll ret=n-n/2,r=2;
    while(r*r<=n) ret+=calcMu(n/r)+(n/r-n/(r+1))*calcMu(r),r++;
    if(n/r<r-1) ret-=calcMu(r-1);
    return Hash[n]=1-ret;
}

ll calcMuS(ll n){
    ll ret=0;
    for(int i=1;i<=n/i;i++){
        ret+=n/i/i*mu[i];
    }
    return ret;
}

int main(){
    Sieve();
    ll d,k;
    cin>>d>>k;
    if(d==0){
        ll l=2*k,r=min(4*k,INF),mid;
        while(r>l){
            mid=(l+r)/2;
            if(mid-calcMuS(mid)>=k) r=mid;
            else l=mid+1;
        }
        cout<<r<<endl;
    }else if(d==1){
        ll l=2*k,r=min(4*k,INF),mid;
        while(r>l){
            mid=(l+r)/2;
            if((calcMu(mid)+calcMuS(mid))/2>=k) r=mid;
            else l=mid+1;
        }
        cout<<r<<endl;
    }else{
        ll l=2*k,r=min(4*k,INF),mid;
        while(r>l){
            mid=(l+r)/2;
            if((calcMuS(mid)-calcMu(mid))/2>=k) r=mid;
            else l=mid+1;
        }
        cout<<r<<endl;
    }
    return 0;
}