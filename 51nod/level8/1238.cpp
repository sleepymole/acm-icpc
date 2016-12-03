#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int P=1000000007;
const int N=10000000;
int prime[N+1],f[N+1];

inline int sum1(ll n){
    n%=P;
    return n*(n+1)%P*500000004%P;
}

inline int sum2(ll n){
    n%=P;
    return n*(n+1)%P*(2*n+1)%P*166666668%P;
}
inline int sum3(ll n){
    int x=sum1(n);
    return (ll)x*x%P;
}

unordered_map<ll,int>Hash;
int calS(ll n){
    if(n<=N) return f[n];
    if(Hash.count(n)) return Hash[n];
    ll ret=(sum3(n)-sum2(n)+sum2(n/2))%P,r=2;
    while(r<=n/r) ret=(ret-(ll)r*r%P*calS(n/r)-
        (ll)(sum2(n/r)-sum2(n/(r+1)))%P*calS(r))%P,r++;
    if(n/r<r-1) ret=(ret+(r-1)*(r-1)*calS(n/(r-1)))%P;
    return Hash[n]=ret;
}

int main(){
    f[1]=1;
    for(int i=2;i<=N;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            f[i]=i-1;
        }
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                f[i*prime[j]]=f[i]*prime[j];
                break;
            }else{
                f[i*prime[j]]=f[i]*(prime[j]-1);
            }
        }
        f[i]=(f[i-1]+(ll)i*i%P*f[i])%P;
    }
    ll n;
    cin>>n;
    int ans=0,r=1;
    while(r<=n/r) ans=(ans+(ll)r*calS(n/r)+
        (ll)(sum1(n/r)-sum1(n/(r+1)))*calS(r))%P,r++;
    if(n/r<r-1) ans=(ans-(ll)(r-1)*calS(n/(r-1)))%P;
    ans=(ans+P)%P;
    cout<<ans<<endl;
    return 0;
}