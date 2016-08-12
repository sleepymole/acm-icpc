#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[101][101],a[101],sum[101];

int solve(int x,int y){
    if(x==y) return 0;
    if(dp[x][y]>0) return dp[x][y];
    int ans=INF;
    for(int i=x;i<y;i++){
        int s=sum[y]-sum[x-1]+solve(x,i)+solve(i+1,y);
        ans=min(ans,s);
    }
    return dp[x][y]=ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    cout<<solve(1,n)<<endl;
    return 0;
}