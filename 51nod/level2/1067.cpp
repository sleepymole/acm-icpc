#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0||(n-2)%7==0) cout<<"B"<<endl;
        else cout<<"A"<<endl;
    }
    return 0;
}