#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const long double PI=acos(-1.0);
const int mod=100003;
const int N=1<<16;

struct Complex{
    long double x,y;
    Complex(long double _x=0.0,long double _y=0.0):x(_x),y(_y){}
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

void transform(Complex x[],int n,int on){
    for(int i=0,j=0;i<n;i++){
        if(i<j) swap(x[i],x[j]);
        for(int k=n>>1;(j^=k)<k;k>>=1);
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

int a[N],f[N];
Complex x[N];
void solve(Complex x[],int l,int r){
    if(l==r){
        x[0]=Complex(1,0);
        x[1]=Complex(a[l],0);
        return;
    }
    int n=r-l+1,len=1;
    while(len<(n+1)) len<<=1;
    int mid=(l+r)/2;
    solve(x,l,mid);
    Complex *y=new Complex[len];
    copy(x,x+len,y);
    fill(x,x+len,Complex(0,0));
    solve(x,mid+1,r);
    transform(x,len,1);
    transform(y,len,1);
    for(int i=0;i<len;i++){
        x[i]=x[i]*y[i];
    }
    transform(x,len,-1);
    delete[]y; y=NULL;
    for(int i=0;i<=n;i++){
        x[i].x=(ll)(x[i].x+0.5)%mod;
        x[i].y=0;
    }
    for(int i=n+1;i<len;i++){
        x[i]=Complex(0,0);
    }
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    solve(x,0,n-1);
    while(q--){
        int k;
        scanf("%d",&k);
        printf("%d\n",(int)x[k].x);
    }
    return 0;
}