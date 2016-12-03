#include<iostream>
using namespace std;
typedef long long ll;
int a[10],m[10];

void gcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1;y=0;}
    else{gcd(b,a%b,y,x);y-=x*(a/b);}
}
ll china(int n,int a[],int m[]){
    ll M=1,d,y,x=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        ll w=M/m[i];
        gcd(m[i],w,d,y);
        x=(x+y*w*a[i])%M;
    }
    return (x+M)%M;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i]>>a[i];
    }
    cout<<china(n,a,m)<<endl;
    return 0; 
}