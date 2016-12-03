#include<unordered_map>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=3000000;
const int P=1000000007;
int prime[N+1],Phi[N+1];

inline int sum(int n){
    return (ll)n*(n+1)%P*500000004%P;
}

inline int sum2(int n){
    return (ll)n*(n+1)%P*(2*n+1)%P*166666668%P;
}

unordered_map<int,int>Hash;
int calPhi(int n){
    if(n<=N) return Phi[n];
    if(Hash.count(n)) return Hash[n];
    int ret=(sum2(n)-sum(n)+sum(n/2))%P,r=2;
    while(r<=n/r) ret=(ret-(ll)r*calPhi(n/r)-
        (ll)(sum(n/r)-sum(n/(r+1)))*calPhi(r))%P,r++;
    if(n/r<(r-1)) ret=(ret+(ll)(r-1)*calPhi(n/(r-1)))%P;
    return Hash[n]=ret;
}

int F(int n){
    int ret=n,r=1;
    while(r<=n/r) ret=(ret+calPhi(n/r)+(ll)(n/r-n/(r+1))*calPhi(r))%P,r++;
    if(n/r<(r-1)) ret=(ret-calPhi(n/(r-1)))%P;
    ret=(ll)ret*500000004%P;
    return ret;
}

int main(){
    Phi[1]=1;
    for(int i=2;i<=N;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            Phi[i]=i-1;
        }
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                Phi[i*prime[j]]=Phi[i]*prime[j];
                break;
            }else{
                Phi[i*prime[j]]=Phi[i]*(prime[j]-1);
            }
        }
        Phi[i]=(Phi[i-1]+(ll)i*Phi[i])%P;
    }
    int a,b;
    cin>>a>>b;
    int ans=(F(b)-F(a-1))%P;
    ans=(ans+P)%P;
    cout<<ans<<endl;
    return 0;
}