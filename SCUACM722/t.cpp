#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=110;
int dist[maxn][maxn],lowc[maxn];
bool vis[maxn];

int Prim(int n){
    int ans=0;
    vis[1]=true;
    for(int i=2;i<=n;i++){
        lowc[i]=dist[1][i];
    }
    for(int i=2;i<=n;i++){
        int minc=inf,p=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&minc>lowc[j]){
                minc=lowc[j];
                p=j;
            }
        }
        ans+=minc;
        vis[p]=true;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&lowc[j]>dist[p][j]){
                lowc[j]=dist[p][j];
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
    int Q,x,y;
    cin>>Q;
    while(Q--){
        cin>>x>>y;
        dist[x][y]=dist[y][x]=0;
    }
    cout<<Prim(n)<<endl;
    return 0;
}