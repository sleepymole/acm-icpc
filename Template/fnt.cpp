#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int G=3;
const int N=1<<21;

int inv(int a,int m){
    return a==1?1:(ll)inv(m%a,m)*(m-m/a)%m;
}

int pow_mod(int a,int n){
    int r=1,k=n>0?n:-n;
    while(k){
        if(k%2) r=(ll)r*a%mod;
        a=(ll)a*a%mod;
        k/=2;
    }
    if(n<0) r=inv(r,mod);
    return r;
}

void fnt(int x[],int n,int on){
    for(int i=0,j=0;i<n;i++){
        if(i<j) swap(x[i],x[j]);
        for(int k=n>>1;(j^=k)<k;k>>=1);
    }
    for(int h=2;h<=n;h<<=1){
        int wn=pow_mod(G,on*(mod-1)/h);
        for(int j=0;j<n;j+=h){
            int w=1;
            for(int k=j;k<j+h/2;k++){
                int u=x[k],v=(ll)w*x[k+h/2]%mod;
                x[k]=(u+v)%mod;x[k+h/2]=(u-v+mod)%mod;
                w=(ll)w*wn%mod;
            }
        }
    }
    if(on==-1){
        int v=inv(n,mod);
        for(int i=0;i<n;i++){
            x[i]=(ll)x[i]*v%mod;
        }
    }
}

int main(){
    
    return 0;
}