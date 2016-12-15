#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        puts("-1");
        return 0;
    }
    int x,y,z;
    x=n;y=n+1;z=n*n+n;
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}