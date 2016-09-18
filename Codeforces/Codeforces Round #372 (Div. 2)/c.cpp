#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int n;
    cin>>n;
    long long num=2;
    long long l=1;
    for(int i=1;i<=n;i++){
        cout<<(l*(l+1)*(l+1)-num)<<endl;
        num=l;
        l++;
    }
    return 0;
}