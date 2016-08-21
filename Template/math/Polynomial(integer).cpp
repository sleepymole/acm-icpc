#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int G=3;

//求a关于m的逆,要求a>0&&a<m&&(a,m)=1
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

//快速数论变换,n必须为2^k形式
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
        int inv=inverse(n%mod,mod);
        for(int i=0;i<n;i++){
            x[i]=(ll)x[i]*inv%mod;
        }
    }
}

//多项式求逆(数论版) 结果存放在b中,b需要初始化
void polynomial_inverse(int a[],int b[],int n){
    int len=1;
    while(len<n) len<<=1;
    int *tmp=new int[len<<1]; //视情况而定,若调用较多，可改为静态数组
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

//多项式开方(数论版),结果存放在b中,b需要初始化
void polynomial_sqrt(int a[],int b[],int n){
    int len=1;
    while(len<n) len<<=1;
    int *tmp=new int[len<<1]; //视情况而定,若调用较多，可改为静态数组
    b[0]=1;//若A(x)的常数项不为1,b[0]应该等于a[0]关于mod的二次剩余
    for(int h=2;h<=len;h<<=1){
        int p=h<<1;
        fill(tmp,tmp+p,0);
        polynomial_inverse(b,tmp,h);
        transform(b,h,1);
        for(int i=0;i<h;i++){
            b[i]=(ll)b[i]*b[i]%mod;
        }
        transform(b,h,-1);
        int inv2=inverse(2,mod);
        for(int i=0;i<h;i++){
            b[i]=(ll)(b[i]+a[i])*inv2%mod;
        }
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

//多项式求对数,结果存放在b中,b数组需要初始化
void polynomial_logarithm(int a[],int b[],int n){
    int p=1;
    while(p<(n<<1)) p<<=1;
    int *tmp=new int[p]; //视情况而定,若调用较多，可改为静态数组
    fill(tmp,tmp+p,0);
    polynomial_inverse(a,tmp,n);
    copy(a,a+n,b);
    for(int i=0;i<n-1;i++){ //求导
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
        b[i]=(ll)b[i-1]*inverse(i,mod)%mod;
    }
    b[0]=0;//视情况而定
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

//多项式除法(数论版),A(x)=D(x)B(x)+R(x),A(x)和B(x)分别为n-1次和m-1次多项式
//A(x)和B(x)的常数项不能为0
void polynomial_division(int a[],int n,int b[],int m,int d[],int r[]){
    int *a0=new int[n<<1];
    int *b0=new int[n<<1];
    int p=1,t=n-m+1;
    while(p<(t<<1)) p<<=1;
    reverse_copy(b,b+m,a0);
    fill(a0+m,a0+p,0);
    fill(b0,b0+p,0);
    polynomial_inverse(a0,b0,t);
    reverse_copy(a,a+n,a0);
    fill(a0+t,a0+p,0);
    transform(a0,p,1);
    transform(b0,p,1);
    for(int i=0;i<p;i++){
        a0[i]=(ll)a0[i]*b0[i]%mod;
    }
    transform(a0,p,-1);
    fill(a0+t,a0+p,0);
    reverse(a0,a0+t);
    copy(a0,a0+t,d);
    while(p<n) p<<=1;
    copy(b,b+m,b0);
    fill(b0+m,b0+p,0);
    transform(a0,p,1);
    transform(b0,p,1);
    for(int i=0;i<p;i++){
        a0[i]=(ll)a0[i]*b0[i]%mod;
    }
    transform(a0,p,-1);
    for(int i=0;i<m;i++){
        r[i]=(a[i]-a0[i]+mod)%mod;
    }
    delete[]a0;a0=NULL;
    delete[]b0;b0=NULL;
}

int main(){
    int startTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    
    int endTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    cout<<(endTime-startTime)<<"ms"<<endl;
    return 0;
}