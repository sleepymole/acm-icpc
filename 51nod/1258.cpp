#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int p[]={7340033,23068673,998244353};
const int N=1<<17,G=3;

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

void polynomial_inverse(int a[],int b[],int n,int m){
    int len=1;
    while(len<n) len<<=1;
    int *tmp=new int[len<<1];
    b[0]=inverse(a[0]%m,m);
    for(int h=2;h<=len;h<<=1){
        int p=h<<1;
        copy(a,a+h,tmp);
        fill(tmp+h,tmp+p,0);
        transform(b,p,1,m);
        transform(tmp,p,1,m);
        for(int i=0;i<p;i++){
            b[i]=(ll)(2-(ll)tmp[i]*b[i]%m+m)*b[i]%m;
        }
        transform(b,p,-1,m);
        fill(b+h,b+p,0);
    }
    fill(b+n,b+len,0);
    delete[]tmp;tmp=NULL;
}

int a[3][N],b[3][N];

void initial(){
    int x=1;
    a[0][0]=a[1][0]=a[2][0]=1;
    for(int i=1;i<(N>>1);i++){
        x=(ll)x*(i+1)%mod;
        a[0][i]=inverse(x,mod);
        a[2][i]=a[1][i]=a[0][i];
    }
    for(int s=0;s<3;s++){
        polynomial_inverse(a[s],b[s],N>>1,p[s]);
    }
}
void merge(){
    ll w[3],y[3];
    w[0]=(ll)p[1]*p[2];w[1]=(ll)p[0]*p[2];w[2]=(ll)p[0]*p[1];
    y[0]=1797855;y[1]=5718385;y[2]=-491958351;
    __int128 M=(__int128)p[0]*p[1]*p[2],wy[3],sum;
    for(int s=0;s<3;s++){
        wy[s]=(__int128)w[s]*y[s]%M;
        wy[s]=(wy[s]+M)%M;
    }
    int r=1;
    for(int i=1;i<(N>>1);i++){
        sum=0;r=(ll)r*i%mod;
        for(int s=0;s<3;s++){
            sum=(sum+wy[s]*b[s][i]%M)%M;
        }
        b[0][i]=sum%mod;
        b[0][i]=(ll)b[0][i]*r%mod;
    }
}

int main(){
    initial();
    merge();
    int T;
    cin>>T;
    while(T--){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll ans=0,r1=1,r2=1;
        for(int i=1;i<=k+1;i++){
            r1=r1*(k-i+2)%mod*inverse(i,mod)%mod;
            r2=r2*(n+1)%mod;
            ans=(ans+r1*r2%mod*b[0][k+1-i]%mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}