#include<iostream>
#include<cstdio>
using namespace std;

void gcd(int a,int b,int &d,int &x,int &y){
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int inv(int a,int n){
    int d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<inv(m,n)<<endl;
    return 0;
}