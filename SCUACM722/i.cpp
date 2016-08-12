#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=101;
int linker[maxn],m,n;
bool g[maxn][maxn],used[maxn];
bool dfs(int u){
    for(int v=1;v<=n;v++){
        if(g[u][v]&&!used[v]){
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v])){
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungray(){
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=1;u<=m;u++){
        memset(used,false,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
int main(){
    int ca=1;
    while(cin>>m>>n){
        int k,x,y;
        cin>>k;
        memset(g,false,sizeof(g));
        while(k--){
            cin>>x>>y;
            g[x][y]=true;
        }
        int Max=hungray(),ans=0;
        for(int u=1;u<=m;u++){
            for(int v=1;v<=n;v++){
                if(g[u][v]){
                    g[u][v]=false;
                    if(hungray()<Max) ans++;
                    g[u][v]=true;
                }

            }
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",ca++,ans,Max);
    }
    return 0;
}