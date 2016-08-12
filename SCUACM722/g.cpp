#include<bits/stdc++.h>
using namespace std;
int n,f[30][6];
struct Matrix{
    unsigned int mat[150][150];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator*(const Matrix &rhs){
        Matrix res;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    res.mat[i][j]+=mat[i][k]*rhs.mat[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator^(int k){
        Matrix res,a=(*this);
        for(int i=0;i<n;i++) res.mat[i][i]=1;
        while(k){
            if(k%2) res=res*a;
            a=a*a;
            k/=2;
        }
        return res;
    }
};
unsigned int solve(int base,int score){
    memset(f,0,sizeof(f));
    for(int i=1;i<base;i++) f[0][i]=1;
    for(int i=1;i<(base-1)*(base-1);i++){
        for(int j=0;j<base;j++){
            for(int k=0;k<base;k++){
                if(j==k) continue;
                int r=(j-k)*(j-k);
                if(i>=r){
                    f[i][j]+=f[i-r][k];
                }
            }
        }
    }
    n=(base-1)*(base-1)*base;
    Matrix res;
    for(int i=0;i<n;i++){
        res.mat[0][i]=f[i/base][i%base];
    }
    Matrix A;
    for(int i=base;i<n;i++){
        A.mat[i][i-base]=1;
    }
    int s=(base-1)*(base-1)-1;
    for(int j=0;j<base;j++){
        for(int k=0;k<base;k++){
            if(j==k) continue;
            int r=(j-k)*(j-k);
            A.mat[(s-r+1)*base+k][s*base+j]=1;
        }
    }
    unsigned int ans=0;
    res=res*(A^(score));
    for(int i=0;i<base;i++){
        ans=ans+res.mat[0][i];
    }
    return ans;
}
int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        int base,score;
        cin>>base>>score;
        cout<<"Case "<<ca<<": "<<solve(base,score)<<endl;
    }
    return 0;
}