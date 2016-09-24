#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const long double PI = acos(-1.0);
const double eps=1e-8;
long double A,B;

long double f(long double x){
    long double ans=0.0;
    for(int k=1;k<=10000;k++){
        ans+=(A/(k+sin(k)))*sin(x+k)+(B/(k+cos(k)))*cos(x+k);
    }
    return ans;
}

int main(){
    long double n;
    cin>>A>>B>>n;
    long double l=0.0,r=PI-eps,mid,x1,x2;
    for(int i=0;i<100;i++){
        mid=(l+r)/2;
        x1=f(l),x2=f(mid);
        if(x1*x2<0.0){
            r=mid;
        }else{
            l=mid;
        }
    }
    long double root=(l+r)/2;
    double ans=n*root+n*(n-1)*PI/2;
    printf("%.3f\n",ans);
    return 0;
}