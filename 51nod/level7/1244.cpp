#include<cmath>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const int N=10000000;

int prime[N+1],M[N+1];
void preMob(){
    M[1]=1;
    for(int i=2;i<=N;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            M[i]=-1;
        }
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                M[i*prime[j]]=0;
                break;
            }else{
                M[i*prime[j]]=-M[i];
            }
        }
        M[i]+=M[i-1];
    }
}

map<ll,ll>mp;
ll calMob(ll n){
    if(n<=N) return M[n];
    if(mp.count(n)) return mp[n];
    ll ret=1;
    int r=sqrt(n);
    ret-=n-n/2;
    for(int i=2;i<=r;i++){
        ret-=calMob(n/i)+(n/i-n/(i+1))*calMob(i);
    }
    if(n/r<(r+1)) ret+=calMob(r);
    return mp[n]=ret;
}

int main(){
    preMob();
    ll a,b;
    scanf("%I64d%I64d",&a,&b);
    cin>>a>>b;
    printf("%I64d\n",calMob(b)-calMob(a-1));
    return 0;
}