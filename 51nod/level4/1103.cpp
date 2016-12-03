#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=50010;
int a[maxn],sum;

int main(){
    int n,s,e;
    cin>>n;
    map<ll,int>mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum=(a[i]+sum)%n;
        if(mp[sum]){
            s=mp[sum]+1;
            e=i;
            break;
        }
        if(sum==0){
            s=1;
            e=i;
            break;
        }
        mp[sum]=i;
    }
    cout<<e-s+1<<endl;
    for(int i=s;i<=e;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}