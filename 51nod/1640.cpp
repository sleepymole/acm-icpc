#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=200010;
int fa[maxn],n,m;

struct Edge{
    int u,v,w;
    Edge(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
    bool operator<(const Edge& rhs)const{
        return w<rhs.w;
    }
};

void initial(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

int findset(int x){
    return x==fa[x]?x:fa[x]=findset(fa[x]);
}

inline int read(){
    int x=0,sgn=1;
    char ch=getchar();
    while(!(ch=='-'||(ch>='0'&&ch<='9'))) ch=getchar();
    if(ch=='-') {sgn=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*sgn;
}

int main(){
    n=read();m=read();
    vector<Edge>e;
    while(m--){
        int u,v,w;
        u=read();v=read();w=read();
        e.push_back(Edge(u,v,w));
    }
    sort(e.begin(),e.end());
    int k=n,sz=e.size(),max_w;
    initial();
    for(int i=0;i<sz;i++){
        int x=findset(e[i].u);
        int y=findset(e[i].v);
        if(x!=y){
            fa[x]=y;k--;
            max_w=e[i].w;
            if(k==1) break;
        }
    }
    initial();
    ll ans=0;k=n;
    for(int i=sz-1;i>=0;i--){
        if(e[i].w>max_w) continue;
        int x=findset(e[i].u);
        int y=findset(e[i].v);
        if(x!=y) {
            fa[x]=y;k--;
            ans+=e[i].w;
            if(k==1) break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}