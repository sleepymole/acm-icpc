#include<iostream>
using namespace std;
int n,m;
char str[55][55];
bool vis[55][55];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

bool dfs(int x,int y,int sta){
    vis[x][y]=true;
    bool flag=false;
    for(int i=0;i<4;i++){
        if(i!=sta){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&str[nx][ny]==str[x][y]){
                if(vis[nx][ny]) return true;
                else{
                    if(dfs(nx,ny,(i+2)%4)) flag=true;
                }
            }
        }
    }
    return flag;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]) continue;
            if(dfs(i,j,-1)){
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}