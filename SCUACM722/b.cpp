#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int mp[15][15],vis[15][1<<15],n,m;
double dp[15][1<<15];

double dfs(int u,int sta){
    if(sta+1==(1<<n)){
        vis[u][sta]=1;
        return dp[u][sta]=0.0;
    }
    if(vis[u][sta]!=0) return dp[u][sta];
    int cnt=0;
    double ans=5.0;
    for(int v=0;v<n;v++){
        if(mp[u][v]==INF||(sta>>v&1))continue;
        dfs(v,sta|1<<v);
        if(vis[v][sta|1<<v]!=1)continue;
        ans+=dp[v][sta|1<<v]+mp[u][v];
        cnt++;
    }
    if(cnt==0){
        vis[u][sta]=-1;
        return dp[u][sta]=0.0;
    }
    vis[u][sta]=1;
    return dp[u][sta]=ans/cnt;
}
int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i][j]=(i!=j)*INF;
            }
        }
        memset(vis,0,sizeof(vis));
        int u,v,w;
        while(m--){
            cin>>u>>v>>w;
            mp[u][v]=mp[v][u]=w;
        }
        printf("Case %d: %.10lf\n",ca,dfs(0,1));
    }
    return 0;
}