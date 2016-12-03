#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int f[1001][20001];

int main(){
    f[0][0]=1;
    for(int i=1;i<=1000;i++){
        f[i][0]=1;
        for(int j=1;j<=20000;j++){
            f[i][j]=(f[i][j-1]+f[i-1][j])%mod;
            if(j>=i) f[i][j]=(f[i][j]-f[i-1][j-i])%mod;
            f[i][j]=(f[i][j]+mod)%mod;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        printf("%d\n",f[n][k]);
    }
    return 0;
}