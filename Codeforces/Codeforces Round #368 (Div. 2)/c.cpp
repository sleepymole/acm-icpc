#include<iostream>
using namespace std;

int main(){
    long long  x;
    cin>>x;
    if(x==1||x==2) cout<<-1<<endl;
    else if(x%2==1){
        long long n=(x-1)/2;
        long long  b=2*n*n+2*n;
        long long  c=2*n*n+2*n+1;
        cout<<b<<" "<<c<<endl;
    }else{
        long long n=x/2;
        long long b=n*n-1;
        long long c=n*n+1;
        cout<<b<<" "<<c<<endl;
    }
    return 0;
}