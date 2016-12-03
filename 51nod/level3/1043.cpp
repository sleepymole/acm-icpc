#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int maxn=1001;
int dp1[maxn][maxn*9];
int dp2[maxn][maxn*9];
int main(){
    int n;
    cin>>n;
    dp1[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=9*i;j++){
            for(int k=0;k<=9;k++){
                dp1[i+1][j+k]=(dp1[i+1][j+k]+dp1[i][j])%mod;
            }
        }
    }
    for(int i=1;i<=9;i++) dp2[1][i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=9*i;j++){
            for(int k=0;k<=9;k++){
                dp2[i+1][j+k]=(dp2[i+1][j+k]+dp2[i][j])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=9*n;i++){
        ans=(ans+(ll)dp1[n][i]*dp2[n][i]%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}