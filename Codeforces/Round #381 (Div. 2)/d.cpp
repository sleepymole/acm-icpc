#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=200010;
int a[maxn],p[maxn],w[maxn];
vector<int>e[maxn];
int s[maxn],c[maxn],ans;

void dfs(int u,int d){
    s[d++]=u;
    
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        scanf("%d%d",&p[i],&w[i]);
        e[p[i]].push_back(i);
    }

    return 0;
}