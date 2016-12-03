#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1000000007;

int inverse(int a){
    return a==1?1:(ll)inverse(mod%a)*(mod-mod/a)%mod;
}

int main(){
    int n,m;
    cin>>n>>m;
    n-=2;m-=2;
    if(n<0||m<0){
        cout<<0<<endl;
    }else{
        int P=1,Q=1;
        for(int i=1;i<=(m+n);i++){
            P=(ll)P*i%mod;
        }
        for(int i=1;i<=m;i++){
            Q=(ll)Q*i%mod;
        }
        for(int i=1;i<=n;i++){
            Q=(ll)Q*i%mod;
        }
        int ans=(ll)P*inverse(Q)%mod;
        cout<<ans<<endl;
    }
    return 0;
}