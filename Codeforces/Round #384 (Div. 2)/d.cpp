#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=200010;
const ll inf=2e18;
vector<int>e[maxn];
int a[maxn];
ll b[maxn];
bool vis[maxn];

ll ans=-inf;
ll dfs(int u){
    vis[u]=true;
    b[u]=a[u];
    priority_queue<ll>q;
    ll Max=-inf;
    for(int i=0;i<int(e[u].size());i++){
        int v=e[u][i];
        if(!vis[v]){
            ll t=dfs(v);
            Max=max(Max,t);
            q.push(t);
            b[u]+=b[v];
        }
    }
    if(q.size()>1){
        ll tmp=q.top();q.pop();
        tmp+=q.top();
        ans=max(ans,tmp);
    }
    return max(Max,b[u]);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    if(ans+inf!=0) printf("%lld\n",ans);
    else puts("Impossible");
    return 0;
}