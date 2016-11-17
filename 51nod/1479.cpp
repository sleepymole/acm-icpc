#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){d=a;x=1;y=0;}
    else{exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int power_mod(int a,ll n,int p){
    int r=1;
    while(n){
        if(n&1) r=(ll)r*a%p;
        a=(ll)a*a%p;
        n>>=1;
    }
    return r;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int m,a,b,c;
        scanf("%d%d%d%d",&m,&a,&b,&c);
        int p=m,r=0;
        while(p%2==0) p>>=1,r++;
        if(p==1){
            if(a==1&&b==1) printf("%d %d 1\n",m/2,m-m/2+1);
            else if(a!=1) printf("%d 1 1\n",power_mod(2,(r-1)/a+1,m));
            else printf("1 %d 1\n",power_mod(2,(r-1)/b+1,m));
            continue;
        }
        ll l,k,d;
        exgcd(c,-(ll)a*b,d,l,k);
        if(d<0) l=-l,k=-k;
        if(k<0){
            int t=(-k-1)/c+1;
            k+=(ll)c*t; l+=(ll)a*b*t;
        }
        while(k<0){ l+=(ll)a*b;k+=c;}
        int x=power_mod(2,(ll)k*b,m);
        int y=power_mod(2,(ll)k*a,m);
        int z=power_mod(2,l,m);
        printf("%d %d %d\n",x,y,z);
    }
    return 0;
}