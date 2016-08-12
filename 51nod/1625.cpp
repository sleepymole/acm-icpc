#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[10][200],b[10][200],r[200];
int main(){
    ll n,m,x,k;
    cin>>n>>m>>x>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    ll ans=0;
    for(int sta=0;sta<(1<<n);sta++){
        ll cnt=k;
        for(int i=0;i<n;i++){
            if(sta&(1<<i)){
                for(int j=0;j<m;j++){
                    b[i][j]=x;
                }
                cnt--;
            }
        }
        if(cnt>=0){
            memset(r,0,sizeof(r));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    r[j]+=b[i][j];
                }
            }
            sort(r,r+m);
            ll sum=0;
            for(int i=0;i<m;i++){
                sum+=i<cnt&&(ll)x*n>r[i]?(ll)x*n:r[i];
            }
            ans=max(ans,sum);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                b[i][j]=a[i][j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}