#include<iostream>
#include<cstdlib>
using namespace std;

long long power_mod(long long a,long long n,long long m){
    long long r=1;
    while(n){
        if(n%2) r=(__int128)r*a%m;
        a=(__int128)a*a%m;
        n/=2;
    }
    return r;
}

long long witness(long long a,long long p){
    long long q=p-1,k=0;
    while(q%2==0){
        k++;q/=2;
    }
    long long v=power_mod(a,q,p);
    if(v==1||v==p-1) return false;
    while(k--){
        v=(__int128)v*v%p;
        if(v==p-1) return false;
    }
    return true;
}

bool miller_rabin(long long p){
    if(p==1||p%2==0) return false;
    if(p==2) return true;
    for(int i=0;i<50;i++){
        long long a=rand()%(p-1)+1;
        if(witness(a,p)) return false;
    }
    return true;
}

int main(){
    long long p;
    while(cin>>p){
        if(miller_rabin(p)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}