#include<iostream>
using namespace std;
int tower[501][501];
int dp[501][501];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>tower[i][j];
        }
    }
    dp[1][1]=tower[1][1];
    for(int i=2;i<=n;i++){
        dp[i][1]=dp[i-1][1]+tower[i][1];
        dp[i][i]=dp[i-1][i-1]+tower[i][i];
        for(int j=2;j<i;j++){
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+tower[i][j];
        }
    }
    int ans=0;
    for(int j=1;j<=n;j++){
        if(dp[n][j]>ans)ans=dp[n][j];
    }
    cout<<ans<<endl;
    return 0;
}