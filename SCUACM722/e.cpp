#include<bits/stdc++.h>
using namespace std;
int n;
struct Matrix{
    int mat[40][40];
};
Matrix multiply(Matrix x,Matrix y){
    Matrix res;
    memset(res.mat,0,sizeof(res.mat));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                res.mat[i][j]=(res.mat[i][j]+x.mat[i][k]*y.mat[k][j])%10;
            }
        }
    }
    return res;
}
Matrix kpow(Matrix a,int k){
    Matrix res;
    memset(res.mat,0,sizeof(res.mat));
    for(int i=0;i<n;i++) res.mat[i][i]=1;
    while(k){
        if(k%2) res=multiply(res,a);
        a=multiply(a,a);
        k/=2;
    }
    return res;
}
Matrix add(Matrix x,Matrix y){
    Matrix res;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res.mat[i][j]=(x.mat[i][j]+y.mat[i][j])%10;
        }
    }
    return res;
}
Matrix solve(Matrix A,int k){
    Matrix res,E;
    memset(E.mat,0,sizeof(E.mat));
    for(int i=0;i<n;i++) E.mat[i][i]=1;
    memset(res.mat,0,sizeof(res.mat));
    if(k==0) return res;
    if(k%2) res=kpow(A,k);
    return add(res,multiply(solve(A,k/2),add(kpow(A,k/2),E)));
}
int main(){
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int k;
    while(cin>>n>>k){
        if(n==0) break;
        Matrix A;
        int x;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>x;
                A.mat[i][j]=x%10;
            }
        }
        Matrix S=solve(A,k);
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                printf("%d ",S.mat[i][j]%10);
            }
            printf("%d\n",S.mat[i][n-1]%10);
        }
        printf("\n");
    }
    return 0;
}