#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod=985661441;
const int G=3;
const int N=1<<20;
int f[N+10],g[N<<1],h[N<<1],fac[N],inv[N];

void initial(){
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=(ll)fac[i-1]*i%mod;
    }
    inv[1]=1;
    for(int i=2;i<N;i++){
        inv[i]=(ll)inv[mod%i]*(mod-mod/i)%mod;
    }
}
int inverse(int a,int m){
    return a==1?1:(ll)inverse(m%a,m)*(m-m/a)%m;
}

int power_mod(int a,int n){
    int r=1,k=n>0?n:-n;
    while(k){
        if(k%2) r=(ll)r*a%mod;
        a=(ll)a*a%mod;
        k/=2;
    }
    if(n<0) r=inverse(r,mod);
    return r;
}

void transform(int x[],int n,int on){
    for(int i=0,j=0;i<n;i++){
        if(i<j) swap(x[i],x[j]);
        for(int k=n>>1;(j^=k)<k;k>>=1);
    }
    for(int h=2;h<=n;h<<=1){
        int wn=power_mod(G,on*(mod-1)/h);
        for(int j=0;j<n;j+=h){
            int w=1;
            for(int k=j;k<j+h/2;k++){
                int u=x[k],t=(ll)w*x[k+h/2]%mod;
                x[k]=(u+t)%mod;
                x[k+h/2]=(u-t+mod)%mod;
                w=(ll)w*wn%mod;
            }
        }
    }
    if(on==-1){
        int Inv=inverse(n%mod,mod);
        for(int i=0;i<n;i++){
            x[i]=(ll)x[i]*Inv%mod;
        }
    }
}

void polynomial_inverse(int a[],int b[],int n){
    int len=1;
    while(len<n) len<<=1;
    int *tmp=new int[len<<1];
    b[0]=inverse(a[0]%mod,mod);
    for(int h=2;h<=len;h<<=1){
        int p=h<<1;
        copy(a,a+h,tmp);
        fill(tmp+h,tmp+p,0);
        transform(b,p,1);
        transform(tmp,p,1);
        for(int i=0;i<p;i++){
            b[i]=(ll)(2-(ll)tmp[i]*b[i]%mod+mod)*b[i]%mod;
        }
        transform(b,p,-1);
        fill(b+h,b+p,0);
    }
    fill(b+n,b+len,0);
    delete[]tmp;tmp=NULL;
}

void polynomial_logarithm(int a[],int b[],int n){
    int p=1;
    while(p<(n<<1)) p<<=1;
    int *tmp=new int[p];
    fill(tmp,tmp+p,0);
    polynomial_inverse(a,tmp,n);
    copy(a,a+n,b);
    for(int i=0;i<n-1;i++){
        b[i]=(ll)b[i+1]*(i+1)%mod;
    }
    b[n-1]=0;
    transform(tmp,p,1);
    transform(b,p,1);
    for(int i=0;i<p;i++){
        b[i]=(ll)tmp[i]*b[i]%mod;
    }
    transform(b,p,-1);
    for(int i=n-1;i>0;i--){
        b[i]=(ll)b[i-1]*inv[i]%mod;
    }
    b[0]=0;
    fill(b+n,b+p,0);
    delete[]tmp;tmp=NULL;
}

void polynomial_exponent(int a[],int b[],int n){
    int len=1;b[0]=1;
    while(len<n) len<<=1;
    int *tmp=new int[len<<1];
    for(int h=2;h<=len;h<<=1){
        int p=h<<1;
        fill(tmp,tmp+p,0);
        polynomial_logarithm(b,tmp,h);
        
        for(int i=0;i<h;i++){
            tmp[i]=((a[i]-tmp[i])%mod+mod)%mod;
        }
        tmp[0]++;
        transform(b,p,1);
        transform(tmp,p,1);
        for(int i=0;i<p;i++){
            b[i]=(ll)b[i]*tmp[i]%mod;
        }
        transform(b,p,-1);
        fill(b+h,b+p,0);
    }
    fill(b+n,b+len,0);
    delete[]tmp;tmp=NULL;
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

int main(){
    initial();
    f[0]=0;
    for(int i=1;i<N;i++){
        f[i]=inverse(fac[i-1],mod);
    }
    polynomial_exponent(f,g,N);
    copy(g,g+N-1,f+1);
    f[0]=0;
    polynomial_exponent(f,h,N);
    for(int i=0;i<N;i++){
        g[i]=(ll)g[i]*fac[i]%mod;
        h[i]=(ll)h[i]*fac[i]%mod;
    }
    int T=read();
    for(int ca=1;ca<=T;ca++){
        int s=read();
        int k=read();
        printf("Case #%d: ",ca);
        if(k==1) putchar('1');
        else if(k==2) write(g[s]);
        else write(h[s]);
        putchar('\n');
    }
    return 0;
}