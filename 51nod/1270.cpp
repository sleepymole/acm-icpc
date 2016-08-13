#include<iostream>
using namespace std;
const int maxn=50010;
int b[maxn],dp[maxn][2];
int abs(int x){
    return x>=0?x:-x;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+b[i-1]-1);
        dp[i][1]=max(dp[i-1][0]+b[i]-1,dp[i-1][1]+abs(b[i-1]-b[i]));
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    return 0;
}