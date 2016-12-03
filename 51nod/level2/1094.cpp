#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=10001;
ll a[maxn],sum[maxn];

void solve(int n,int k){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(sum[j]-sum[i-1]==k){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<"No Solution"<<endl;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    solve(n,k);
    return 0;
}