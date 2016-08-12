#include<bits/stdc++.h>
using namespace std;

struct Matrix{
    int mat[2][2];
};
Matrix mulitply(Matrix a,Matrix b){
    Matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%10000;
            }
        }
    }
    return c;
}

Matrix kpow(Matrix a,int n){
    Matrix r;
    r.mat[0][0]=r.mat[1][1]=1;
    r.mat[0][1]=r.mat[1][0]=0;
    while(n){
        if(n%2) r=mulitply(r,a);
        a=mulitply(a,a);
        n/=2;
    }
    return r;
}
int main(){
    Matrix x;
    x.mat[0][0]=0;
    x.mat[0][1]=x.mat[1][0]=x.mat[1][1]=1;
    int t;
    cin>>t;
    while(t--){
        int a,b,n,m;
        cin>>a>>b>>n>>m;
        Matrix y=kpow(x,n);
        int ans=a*y.mat[0][0]+b*y.mat[1][0];
        if(m==1) cout<<(ans%10)<<endl;
        else if(m==2) cout<<(ans%100)<<endl;
        else if(m==3) cout<<(ans%1000)<<endl;
        else cout<<(ans%10000)<<endl;
    }
    return 0;
}