#include<iostream>
using namespace std;
int mat[55][55];
int main(){
    int n;
    cin>>n;
    int x=1,y=(n+1)/2;
    mat[x][y]=1;
    for(int i=2;i<=n*n;i++){
        if(x-1>0&&y+1>0&&y+1<=n){
            if(mat[x-1][y+1]==0) x--,y++;
            else x++;    
        }else if(x==1){
            if(y<n) x=n,y++;
            else x++;
        }else if(y==n){
            x--;y=1;
        }
        mat[x][y]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}