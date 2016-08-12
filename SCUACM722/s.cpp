#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=110;
const int inf=0x3f3f3f3f;
int dist[maxn][maxn],mp[maxn/2][maxn/2];
int lowc[maxn];
bool vis[maxn],vis2[maxn][maxn];
char str[maxn];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node{
    int x,y,step;
};
void BFS(int x,int y,int m,int n){
    memset(vis2,false,sizeof(vis2));
    Node sta;
    sta.x=x;sta.y=y;sta.step=0;
    queue<Node>q;
    q.push(sta);
    vis2[x][y]=true;
    while(!q.empty()){
        Node tmp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=tmp.x+dir[i][0];
            int ny=tmp.y+dir[i][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&mp[nx][ny]>=0&&!vis2[nx][ny]){
                q.push((Node){nx,ny,tmp.step+1});
                vis2[nx][ny]=true;
                if(mp[nx][ny]>0){
                    dist[mp[x][y]][mp[nx][ny]]=tmp.step+1;
                    dist[mp[nx][ny]][mp[x][y]]=tmp.step+1;
                }
            }
        }
    }
}

int Prim(int n){
    memset(vis,false,sizeof(vis));
    vis[1]=true;
    for(int i=2;i<=n;i++){
        lowc[i]=dist[1][i];
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        int minc=inf;
        int p=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&minc>lowc[j]){
                p=j;
                minc=lowc[j];
            }
        }
        if(p==-1) return -1;
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
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        scanf("%d%d\n",&n,&m);
        int k=0;
        for(int i=0;i<m;i++){
            cin.getline(str,maxn);
            for(int j=0;j<n;j++){
                if(str[j]=='S'||str[j]=='A'){
                    mp[i][j]=++k;
                }else if(str[j]==' '){
                    mp[i][j]=0;
                }else{
                    mp[i][j]=-1;
                }
            }
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                dist[i][j]=(i!=j)*inf;
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<n;j++){
                if(mp[i][j]>0) BFS(i,j,m,n);
            }
        }
        cout<<Prim(k)<<endl;
    }
    return 0;
}