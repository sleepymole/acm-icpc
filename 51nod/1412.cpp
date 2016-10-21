#include<iostream>
#include<cstring>
using namespace std;
const int N=2000;
const int depth=15;
const int mod=1000000007;
int f[N+1][depth+1];

int main(){
    int n;
    cin>>n;
    f[0][0]=f[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=depth;j++){
            for(int k=0;k<i;k++){
                f[i][j]=(1LL*f[k][j-1]*f[i-1-k][j-1]+f[i][j])%mod;
                f[i][j]=(1LL*f[k][j-2]*f[i-1-k][j-1]+f[i][j])%mod;
                f[i][j]=(1LL*f[k][j-1]*f[i-1-k][j-2]+f[i][j])%mod;
            }
        }
    }
    int ans=0;
    for(int j=0;j<=depth;j++){
        ans=(ans+f[n][j])%mod;
    }
    cout<<ans<<endl;
    return 0;
}