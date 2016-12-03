#include<iostream>
using namespace std;
const int mod=1000000007;
int main(){
    long long x,b,c;
    cin>>x>>b>>c;
    int a=2,r=1;
    while(c){
        if(c%2) r=(long long)r*a%mod;
        a=(long long)a*a%mod;
        c/=2;
    }
    cout<<r<<endl;
    return 0;
}