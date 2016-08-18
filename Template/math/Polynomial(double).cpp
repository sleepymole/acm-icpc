#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
const double PI=acos(-1.0);

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

//快速傅里叶变换(浮点型)
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

//多项式求逆(浮点型) deg必须为2的幂次,且数组必须开到deg的两倍
void polynomial_inverse(Complex a[],Complex b[],Complex tmp[],int deg){
    b[0].x=1.0/a[0].x;
    if(deg==1) return;
    for(int h=2;h<=deg;h<<=1){
        copy(a,a+h,tmp);
        int p=h<<1;
        transform(b,p,1);
        transform(tmp,p,1);
        for(int i=0;i<p;i++){
            b[i]=(Complex(2,0)-tmp[i]*b[i])*b[i];
        }
        transform(b,p,-1);
        fill(b+h,b+p,Complex(0,0));
    }
}

int main(){
    int startTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    //TODO
    int endTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    cout<<(endTime-startTime)<<"ms"<<endl;
    return 0;
}