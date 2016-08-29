#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int x[maxn];

int main(){
    int n,a;
    cin>>n>>a;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(a>=x[n]){
        cout<<a-x[2]<<endl;
        return 0;
    }
    if(a<=x[1]){
        cout<<x[n-1]-a<<endl;
        return 0;
    }
    int ans=0x3f3f3f3f,sum=0;

    if(a>=x[2]){
        sum=(a-x[2])*2+x[n]-a;
        ans=min(ans,sum);
    }
    if(a<=x[n-1]){
        sum=(x[n-1]-a)*2+a-x[1];
        ans=min(ans,sum);
    }
    if(a<=x[n]&&a>=x[2]){
        sum=(x[n]-a)*2+a-x[2];
        ans=min(ans,sum);
    }
    if(a>=x[1]&&a<=x[n-1]){
        sum=(a-x[1])*2+x[n-1]-a;
        ans=min(ans,sum);
    }
    if(a>=x[1]&&a<=x[2]){
        sum=x[n]-a;
        ans=min(ans,sum);
    }
    if(a>=x[n-1]&&a<=x[n]){
        sum=a-x[1];
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}