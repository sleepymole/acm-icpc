#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1000000007;

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
    m--;n--;
    int P=1,Q=1;
    for(int i=1;i<=m+n;i++){
        P=(ll)P*i%mod;
    }
    for(int i=1;i<=m;i++){
        Q=(ll)Q*i%mod;
    }
    for(int i=1;i<=n;i++){
        Q=(ll)Q*i%mod;
    }
    int ans=(ll)P*inv(Q,mod)%mod;
    cout<<ans<<endl;
    return 0;
}