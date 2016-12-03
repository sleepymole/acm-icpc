#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int G=3;

int inverse(int a,int m){
    return a==1?1:(ll)inverse(m%a,m)*(m-m/a)%m;
}

int power_mod(int a,int n,int p){
    int r=1,k=n>0?n:-n;
    while(k){
        if(k%2) r=(ll)r*a%p;
        a=(ll)a*a%p;
        k/=2;
    }
    if(n<0) r=inverse(r,p);
    return r;
}

void transform(int x[],int n,int on,int p){
    for(int i=0,j=0;i<n;i++){
        if(i<j) swap(x[i],x[j]);
        for(int k=n>>1;(j^=k)<k;k>>=1);
    }
    for(int h=2;h<=n;h<<=1){
        int wn=power_mod(G,on*(p-1)/h,p);
        for(int j=0;j<n;j+=h){
            int w=1;
            for(int k=j;k<j+h/2;k++){
                int u=x[k],t=(ll)w*x[k+h/2]%p;
                x[k]=(u+t)%p;
                x[k+h/2]=(u-t+p)%p;
                w=(ll)w*wn%p;
            }
        }
    }
    if(on==-1){
        int inv=inverse(n%p,p);
        for(int i=0;i<n;i++){
            x[i]=(ll)x[i]*inv%p;
        }
    }
}

int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

void write(int n){
    if(n>=10)write(n/10);
    putchar(n%10+'0');
}

const int p[]={7340033,23068673,998244353};
const int N=1<<17;
int f[3][N],g[3][N];

int main(){
    ll w[3],y[3];
    w[0]=(ll)p[1]*p[2];w[1]=(ll)p[0]*p[2];w[2]=(ll)p[0]*p[1];
    y[0]=1797855;y[1]=5718385;y[2]=-491958351;
    __int128 M=(__int128)p[0]*p[1]*p[2],wy[3],sum;
    for(int s=0;s<3;s++){
        wy[s]=(__int128)w[s]*y[s]%M;
        wy[s]=(wy[s]+M)%M;
    }
    int n,k,x;
    n=read();k=read();
    for(int i=0;i<n;i++){
        x=read();
        for(int s=0;s<3;s++){
            f[s][i]=x%p[s];
        }
    }
    int len=1;
    while(len<(n<<1)) len<<=1;
    g[2][0]=g[1][0]=g[0][0]=1;
    for(int i=1;i<n;i++){
        g[0][i]=(ll)g[0][i-1]*(k+i-1)%mod*inverse(i,mod)%mod;
        g[2][i]=g[1][i]=g[0][i];
    }
    for(int s=0;s<3;s++){
        transform(f[s],len,1,p[s]);
        transform(g[s],len,1,p[s]);
        for(int i=0;i<len;i++){
            f[s][i]=(ll)f[s][i]*g[s][i]%p[s];
        }
        transform(f[s],len,-1,p[s]);
    }
    for(int i=0;i<n;i++){
        sum=0;
        for(int s=0;s<3;s++){
            sum=(sum+wy[s]*f[s][i]%M)%M;
        }
        f[0][i]=sum%mod;
    }
    for(int i=0;i<n;i++){
        write(f[0][i]);
        putchar('\n');
    }
    return 0;
}