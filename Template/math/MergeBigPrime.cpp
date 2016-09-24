#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int p[]={25*(1<<22)+1,5*(1<<25)+1,7*(1<<26)+1};
const int G=3;
const int N=1<<17;
__int128 M,wy[3],sum;

void merge_initial(){
    ll w[3],y[3];
    w[0]=(ll)p[1]*p[2];w[1]=(ll)p[0]*p[2];w[2]=(ll)p[0]*p[1];
    y[0]=803507;y[1]=12427566;y[2]=-38396896;
    M=(__int128)p[0]*p[1]*p[2];
    for(int s=0;s<3;s++){
        wy[s]=(__int128)w[s]*y[s]%M;
        wy[s]=(wy[s]+M)%M;
    }
}

void merge(int &x,int &y,int &z){
    sum=(x*wy[0]+y*wy[1]+z*wy[2])%M;
    x=y=z=sum%mod;
}


void merge_initial2(){
    wy[0]=34952532LL*p[1];
    wy[1]=111848110LL*p[0];
    M=(__int128)p[0]*p[1];
}

void merge2(int &x,int &y){
    sum=(x*wy[0]+y*wy[1])%M;
    x=y=sum%mod;
}

int main(){
    merge_initial();
    
    return 0;
}