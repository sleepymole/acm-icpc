#include<bits/stdc++.h>
using namespace std;
double dp[1001];

int main(){
    dp[0]=1.0;
    for(int i=2;i<=1000;i+=2){
        dp[i]=1.0*(i-1)/(i+1)*dp[i-2];
    }
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        int x,y;
        cin>>x>>y;
        printf("Case %d: %.10lf\n",ca,dp[x]);
    }
    return 0;
}