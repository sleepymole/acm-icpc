#include<iostream>
using namespace std;

int main(){
    int n,b,d,x,sum=0,ans=0;
    cin>>n>>b>>d;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>b) continue;
        sum+=x;
        if(sum>d) sum=0,ans++;
    }
    cout<<ans<<endl;
    return 0;
}