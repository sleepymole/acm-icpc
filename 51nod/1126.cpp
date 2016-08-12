#include<iostream>
#include<cstring>
using namespace std;

struct Matrix{
    int mat[2][2];
    Matrix operator*(const Matrix &rhs){
        Matrix ans;
        memset(ans.mat,0,sizeof(ans.mat));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ans.mat[i][j]=(ans.mat[i][j]+mat[i][k]*rhs.mat[k][j])%7;
                }
            }
        }
        return ans;
    }
    Matrix operator^(int n){
        Matrix r,a=(*this);
        memset(r.mat,0,sizeof(r.mat));
        for(int i=0;i<2;i++) r.mat[i][i]=1;
        while(n){
            if(n%2) r=r*a;
            a=a*a;
            n/=2;
        }
        return r;
    }
};

int main(){
    int a,b,n;
    cin>>a>>b>>n;
    a=(a%7+7)%7;
    b=(b%7+7)%7;
    Matrix A,B;
    A.mat[0][0]=0;A.mat[0][1]=b;
    A.mat[1][0]=1;A.mat[1][1]=a;
    B.mat[0][0]=0;B.mat[0][0]=0;
    B.mat[1][0]=1;B.mat[1][1]=1;
    Matrix C=B*(A^(n-1));
    cout<<C.mat[1][0]<<endl;
    return 0;
}