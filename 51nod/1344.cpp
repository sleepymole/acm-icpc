#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
int a[1000000000];
int main(){
    ll n,x,ans=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
        if(sum<0) ans-=sum,sum=0;
    }
    cout<<ans<<endl;
    return 0;
}