#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[10010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0,mid=a[n/2];
    for(int i=0;i<n;i++){
        if(mid>a[i]) ans+=mid-a[i];
        else ans+=a[i]-mid;
    }
    cout<<ans<<endl;
    return 0;
}