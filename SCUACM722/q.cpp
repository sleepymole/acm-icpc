#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=101;
const int inf=0x3f3f3f3f;
int dist[maxn][maxn],lowc[maxn];
bool vis[maxn];

int getc(){
    char ch=getchar();
    while(ch<'A'||ch>'Z'){
        ch=getchar();
    }
    return ch-'A';
}
int Prim(int n){
    memset(vis,false,sizeof(vis));
    int ans=0;
    vis[0]=true;
    for(int i=1;i<n;i++){
        lowc[i]=dist[0][i];
    }
    for(int i=1;i<n;i++){
        int minc=inf,p=-1;
        
        for(int j=0;j<n;j++){
            if(!vis[j]&&minc>lowc[j]){
                minc=lowc[j];
                p=j;
            }
        }
        if(p==-1) return -1;
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;j++){
            if(!vis[j]&&lowc[j]>dist[p][j]){
                lowc[j]=dist[p][j];
            }
        }
    }
    return ans;
}
int main(){
    int n;
    while(cin>>n,n!=0){
        int x,y,d,m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=inf;
            }
        }
        for(int i=1;i<n;i++){
            x=getc();
            cin>>m;
            while(m--){
                y=getc();
                cin>>d;
                dist[x][y]=dist[y][x]=d;
            }
        }
        
        cout<<Prim(n)<<endl;
    }
    return 0;
}