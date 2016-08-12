#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(a==(int)((1+sqrt(5))/2*(b-a))) cout<<'B'<<endl;
        else cout<<'A'<<endl;
    }
}