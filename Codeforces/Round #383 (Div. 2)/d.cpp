#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1010;
int pa[maxn],w[maxn],b[maxn];
int f[maxn],g[maxn],h[maxn];
vector<int>v[maxn];

int findset(int x){
    return x==pa[x]?x:(pa[x]=findset(pa[x]));
}

int main(){
    int n,m,W;
    scanf("%d%d%d",&n,&m,&W);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) pa[i]=i;
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        x=findset(x);
        y=findset(y);
        if(x!=y) pa[y]=x;
    }
    for(int i=1;i<=n;i++)
        v[findset(i)].push_back(i);
    for(int i=1;i<=n;i++){
        if(!v[i].empty()){
            int sz=v[i].size();
            int tb=0,tw=0;
            for(int j=0;j<sz;j++){
                memcpy(h,f,(W+1)*sizeof(int));
                int d=v[i][j];
                tb+=b[d];tw+=w[d];
                for(int k=W;k>=w[d];k--){
                    h[k]=max(h[k],h[k-w[d]]+b[d]);
                    g[k]=max(g[k],h[k]);
                }
            }
            memcpy(h,f,(W+1)*sizeof(int));
            for(int k=W;k>=tw;k--){
                h[k]=max(h[k],h[k-tw]+tb);
                g[k]=max(g[k],h[k]);
            }
            for(int j=0;j<=W;j++) f[j]=g[j];
        }
    }
    int ans=0;
    for(int i=0;i<=W;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}