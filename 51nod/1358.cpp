#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int P=1000000007;

struct Poly{
    static int len;
    int a[40];
    Poly(){memset(a,0,sizeof(a));}
    Poly operator*(const Poly rhs)const{
        Poly res;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                res.a[i+j]=(res.a[i+j]+(ll)a[i]*rhs.a[j])%P;
            }
        }
        for(int i=2*len-1;i>=len;i--){
            if(res.a[i]){
                res.a[i-5]=(res.a[i-5]+res.a[i])%P;
                res.a[i-17]=(res.a[i-17]+res.a[i])%P;
                res.a[i]=0;
            }
        }
        return res;
    }
};
int Poly::len=17;

Poly poly_power(ll n){
    Poly base,r;
    base.a[1]=r.a[0]=1;
    while(n){
        if(n%2) 
            r=r*base;
        base=base*base;
        n>>=1;
    }
    return r;
}

int f[21];
int main(){
    ll n;
    cin>>n;
    n*=5;
    if(n<=20){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<=20;i++) f[i]=1;
    Poly p=poly_power(n-4);
    int ans=0;
    for(int i=0;i<17;i++){
        ans=(ans+(ll)f[i]*p.a[i])%P;
    }
    cout<<ans<<endl;
    return 0;
}