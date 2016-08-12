#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const int maxn=100010;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll c[maxn],dp[maxn][2];
string S[maxn];

string reverse(string s){
    string ans;
    for(int i=s.length()-1;i>=0;i--){
        ans.push_back(s[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>S[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i][1]=INF;
    }
    dp[1][0]=0;
    dp[1][1]=c[1];
    for(int i=2;i<=n;i++){
        if(S[i]>=S[i-1]){
            dp[i][0]=min(dp[i-1][0],dp[i][0]);
        }
        if(S[i]>=reverse(S[i-1])){
            dp[i][0]=min(dp[i-1][1],dp[i][0]);
        }
        if(reverse(S[i])>=S[i-1]){
            dp[i][1]=min(dp[i-1][0],dp[i][1]);
        }
        if(reverse(S[i])>=reverse(S[i-1])){
            dp[i][1]=min(dp[i-1][1],dp[i][1]);
        }
        dp[i][1]+=c[i];
    }
    ll ans=min(dp[n][0],dp[n][1]);
    if(ans<INF) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}