#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[501][501];
int main(){
    ll n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                x=i;y=j;
            }
        }
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        ll s=0;
        for(int j=1;j<=n;j++){
            s+=a[i][j];
        }
        if(sum==0) sum=s;
        if(s!=sum){
            cout<<-1<<endl;
            return 0;
        }
    }
    ll s=0;
    for(int j=1;j<=n;j++){
        if(j==y) continue;
        s+=a[x][j];
    }
    a[x][y]=sum-s;
    if(a[x][y]<=0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        s=0;
        for(int j=1;j<=n;j++){
            s+=a[i][j];
        }
        if(s!=sum){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int j=1;j<=n;j++){
        s=0;
        for(int i=1;i<=n;i++){
            s+=a[i][j];
        }
        if(s!=sum){
            cout<<-1<<endl;
            return 0;
        }
    }
    s=0;
    for(int i=1;i<=n;i++){
        s+=a[i][i];
    }
    if(s!=sum){
        cout<<-1<<endl;
        return 0;
    }
    s=0;
    for(ll i=1;i<=n;i++){
        s+=a[i][n+1-i];
    }
    if(s!=sum){
        cout<<-1<<endl;
        return 0;
    }
    cout<<a[x][y]<<endl;
    return 0;
}