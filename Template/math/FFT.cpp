#include<iostream>
#include<cstdio>
#include<cstring>
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

//len必须是2的幂次
void fft(Complex a[],int len,int on){
    for(int i=0,j=0;i<len;i++){
        if(i<j) swap(a[i],a[j]);
        for(int k=len>>1;(j^=k)<k;k>>=1);
    }
    for(int h=2;h<=len;h<<=1){
        Complex wn(cos(2*PI/h),sin(on*2*PI/h));
        for(int j=0;j<len;j+=h){
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++){
                Complex u=a[k];
                Complex t=w*a[k+h/2];
                a[k]=u+t;
                a[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1){
        for(int i=0;i<len;i++){
            a[i].x/=len;
        }
    }
}

int main(){

    return 0;
}