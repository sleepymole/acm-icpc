#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1000010;
char str[maxn];
//a00 a01 a10 a11
//p(p-1)/2==a00      q(q-1)/2=a11
//p^2-p=2*a00
//p^2-p-2*a00=0
int main(){
    ll a00,a01,a10,a11,d,s,p,q,n;
    cin>>a00>>a01>>a10>>a11;
    d=1+8*a00;
    s=(int)(sqrt(d)+0.5);
    if(s*s!=d||s%2==0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    p=(s+1)/2;
    d=1+8*a11;
    s=(int)(sqrt(d)+0.5);
    if(s*s!=d||s%2==0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    q=(s+1)/2;
    n=p+q;
    ll S=n*(n-1)/2;
    if(a00+a01+a10+a11!=S){
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int i=0;i<p;i++){
        str[i]='0';
    }
    for(int i=p;i<n;i++){
        str[i]='1';
    }
    if(p==0||q==0){
        printf("%s\n",str);
        return 0;
    }
    int x=p*q,pos1=p-1,pos2=p-1;
    while(x>a01){
        if(pos2<n-1&&str[pos2+1]=='1'){
            swap(str[pos2],str[pos2+1]);
            pos2++;
            x--;
        }else{
            pos2=pos1-1;
            pos1--;
            if(pos1<0) break;
        }
    }
    if(x==a01)  printf("%s\n",str);
    else cout<<"Impossible"<<endl;
    return 0;
}