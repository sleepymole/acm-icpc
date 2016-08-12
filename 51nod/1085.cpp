#include<iostream>
using namespace std;
int w[101],p[101];
int dp[101][10010];
int main(){
    int n,W;
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>p[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j>=w[i]){
                dp[i][j]=max(dp[i-1][j-w[i]]+p[i],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W]<<endl;
    return 0;
}