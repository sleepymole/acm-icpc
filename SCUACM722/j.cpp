#include<bits/stdc++.h>
using namespace std;
const int maxn=1510;
vector<int>node[maxn];
int n,dp[maxn][2],vis[maxn];

void dfs(int u){
    vis[u]=true;
    dp[u][0]=0;
    dp[u][1]=1;
    vector<int>::iterator it;
    for(it=node[u].begin();it!=node[u].end();it++){
        int v=(*it);
        if(vis[v])continue;
        dfs(v);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++) node[i].clear();
        for(int i=0;i<n;i++){
            int u,v,k;
            scanf("%d:(%d)",&u,&k);
            while(k--){
                scanf("%d",&v);
                node[u].push_back(v);
                node[v].push_back(u);
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(0);
        cout<<min(dp[0][0],dp[0][1])<<endl;
    }
    return 0;
}