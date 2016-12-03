#include<iostream>
using namespace std;
typedef long long ll;
const int mod=10007;

void gcd(int a,int b,int &d,int &x,int &y){
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int inv(int a,int n){
    int d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

int Combination(int m,int n){
    if(m>mod||n>mod) 
        return Combination(m/mod,n/mod)*Combination(m%mod,n%mod)%mod;
    int P=1,Q=1;
    for(int i=1;i<=m;i++) P=P*i%mod;
    for(int i=1;i<=m-n;i++) Q=Q*i%mod;
    for(int i=1;i<=n;i++) Q=Q*i%mod;
    return P*inv(Q,mod)%mod;
}
int main(){
    int n;
    cin>>n;n--;
    int ans=2*inv(n+1,mod)*Combination(2*n,n)%mod;
    cout<<ans<<endl;
    return 0;
}