#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=320000;
int prime[maxn],mu[maxn];

void pre(){
    mu[1]=1;
    for(int i=2;i<maxn;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=prime[0]&&i<maxn/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}

inline ll calc(ll n){
    ll ret=0;
    for(int i=1;i*i<=n/i;i++){
        ret+=3*(n/i/i-i)+1;
        for(int j=i+1;j<=n/i/j;j++){
            ret+=6*(n/i/j-j)+3;
        }
    }
    return ret;
}

inline ll f(ll n){
    ll ret=n;
    for(int i=1;i<=n/i;i++) if(mu[i]) ret+=mu[i]*calc(n/i/i);
    return ret/2;
}

int main(){
    pre();
    ll a,b;
    cin>>a>>b;
    cout<<f(b)-f(a-1)<<endl;
    return 0;
}