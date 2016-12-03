#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1001;
char str[maxn];
int dp[maxn][maxn];
int solve(int i,int j){
    if(dp[i][j]>=0) return dp[i][j];
    if(i==j) return dp[i][j]=0;
    if(i+1==j) return dp[i][j]=str[i]!=str[j];
    if(str[i]==str[j]) return dp[i][j]=solve(i+1,j-1);
    return dp[i][j]=min(solve(i+1,j),solve(i,j-1))+1;
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%s",str);
    int len=strlen(str);
    cout<<solve(0,len-1)<<endl;
    return 0;
}