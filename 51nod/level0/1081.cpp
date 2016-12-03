#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=50010;
ll sum[maxn];
int main(){
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        sum[i]=sum[i-1]+x;
    }
    int q,i,k;
    cin>>q;
    while(q--){
        cin>>i>>k;
        cout<<sum[i+k-1]-sum[i-1]<<endl;
    }
    return 0;
}