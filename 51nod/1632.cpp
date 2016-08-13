#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
typedef long long ll;
const int mod=1000000007;

int pow(int a,int n){
    int r=1;
    while(n){
        if(n%2) r=(ll)r*a%mod;
        a=(ll)a*a%mod;
        n/=2;
    }
    return r;
}

int main(){
    int n;
    cin>>n;
    cout<<(ll)(n+1)*pow(2,n-2)%mod<<endl;
    return 0;
}