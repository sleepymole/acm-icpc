#include<iostream>
using namespace std;
typedef long long ll;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    ll a,b;
    cin>>a>>b;
    cout<<a/gcd(a,b)*b<<endl;
    return 0;
}