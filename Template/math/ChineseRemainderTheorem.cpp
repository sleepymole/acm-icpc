#include<iostream>
using namespace std;
typedef long long ll;

int inverse(int a,int m){
    return a==1?1:(ll)inverse(m%a,m)*(m-m/a)%m;
}

ll CRT(int a[],int m[],int n){
    ll M=1,x=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        ll w=M/m[i];
        ll y=inverse(w%m[i],m[i]);
        x=(x+w*y*a[i])%M;
    }
    return x;
}

int main(){

    return 0;
}