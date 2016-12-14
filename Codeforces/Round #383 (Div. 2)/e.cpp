#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=200010;
int a[maxn],b[maxn],c[maxn];
vector<int>v[maxn];

bool dfs(int u,int t){
    c[u]=t;
    t=t==1?2:1;
    for(int i=0;i<int(v[u].size());i++){
        if(!c[v[u][i]]) dfs(v[u][i],t);
        else if(c[v[u][i]]!=t) return false;
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<2*n;i+=2){
        v[i].push_back(i+1);
        v[i+1].push_back(i);
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    bool flag=true;
    for(int i=1;i<=2*n;i++){
        if(!c[i]) flag=dfs(i,1);
        if(!flag) break;
    }
    if(flag) for(int i=0;i<n;i++) 
        printf("%d %d\n",c[a[i]],c[b[i]]);
    else puts("-1");
    return 0;
}