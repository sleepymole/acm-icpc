#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[15],f[15],d,n,m;
struct Matrix{
    int mat[15][15];
    Matrix operator*(const Matrix &rhs){
        Matrix ans;
        memset(ans.mat,0,sizeof(ans.mat));
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                for(int k=0;k<d;k++){
                    ans.mat[i][j]=(ans.mat[i][j]+mat[i][k]*rhs.mat[k][j])%m;
                }
            }
        }
        return ans;
    }
    Matrix operator^(int n){
        Matrix r,a=(*this);
        memset(r.mat,0,sizeof(r.mat));
        for(int i=0;i<d;i++) r.mat[i][i]=1;
        while(n){
            if(n%2) r=r*a;
            a=a*a;
            n/=2;
        }
        return r;
    }
};
int main(){
    Matrix x;
    while(cin>>d>>n>>m){
        if(n==0&&m==0&&d==0) break;
        memset(x.mat,0,sizeof(x.mat));
        for(int i=0;i<d;i++){
            cin>>a[i];
            x.mat[i][0]=a[i]%m;
        }
        for(int i=0;i<d;i++){
            cin>>f[i];
        }
        for(int j=1;j<d;j++){
            x.mat[j-1][j]=1;
        }
        Matrix s=x^(n-d);
        int ans=0;
        for(int i=0;i<d;i++){
            ans=(ans+(ll)s.mat[i][0]*f[d-1-i])%m;
        }
        cout<<ans<<endl;
    }

    return 0;
}