#include<iostream>
#include<cmath>
using namespace std;

int solve(int n){
    n=2*(n-1);
    int k=sqrt(n);
    if(k*(k+1)==n) return 1;
    else return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}