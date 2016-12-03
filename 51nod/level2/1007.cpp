#include<iostream>
using namespace std;
bool dp[2][10010];
int main(){
    int n,x;
    cin>>n;
    int now=0;
    dp[now][0]=true;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<=10000;j++){
            dp[now^1][j]=false;
        }
        for(int j=0;j<=10000;j++){
            
            if(dp[now][j]){
                if(j>=x) dp[now^1][j-x]=true;
                else dp[now^1][x-j]=true;
                if(j+x<=10000) dp[now^1][j+x]=true;
            }
        }
        now^=1;
    }
    int ans=-1;
    for(int j=0;j<=10000;j++){
        if(dp[now][j]){
            ans=j;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}