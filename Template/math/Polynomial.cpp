#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const int mod=998244353;
const int G=3;

struct Complex{
    double x,y;
    Complex(double _x=0.0,double _y=0.0):x(_x),y(_y){}
    Complex operator+(const Complex& rhs)const{
        return Complex(x+rhs.x,y+rhs.y);
    }
    Complex operator-(const Complex& rhs)const{
        return Complex(x-rhs.x,y-rhs.y);
    }
    Complex operator*(const Complex& rhs)const{
        return Complex(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);
    }
};

//求a在模m下的逆,要求a<m且(a,m)=1
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

//快速数论变换
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

//快速傅里叶变换(浮点型)
void transform(Complex x[],int n,int on){
    for(int i=0,j=0;i<n;i++){
        if(i<j) swap(x[i],x[j]);
        for(int k=n>>1;(j^=k)<k;j++);
    }
    for(int h=2;h<=n;h<<=1){
        Complex wn(cos(2*PI/h),sin(on*2*PI/h));
        for(int j=0;j<n;j+=h){
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++){
                Complex u=x[k],t=w*x[k+h/2];
                x[k]=u+t; x[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1){
        for(int i=0;i<n;i++){
            x[i].x=x[i].x/n;
        }
    }
}

//多项式求逆 deg必须为2的幂次,且数组必须开到deg的两倍
void polynomial_inverse(int a[],int b[],int tmp[],int deg){
    b[0]=inverse(a[0]%mod,mod);
    if(deg==1) return;
    for(int h=2;h<=deg;h<<=1){
        copy(a,a+h,tmp);
        int p=h<<1;
        transform(b,p,1);
        transform(tmp,p,1);
        for(int i=0;i<p;i++){
            b[i]=(ll)(2-(ll)tmp[i]*b[i]%mod+mod)*b[i]%mod;
        }
        transform(b,p,-1);
        fill(b+h,b+p,0);
    }
}

int main(){
    int startTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    
    int endTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    cout<<(endTime-startTime)<<"ms"<<endl;
    return 0;
}