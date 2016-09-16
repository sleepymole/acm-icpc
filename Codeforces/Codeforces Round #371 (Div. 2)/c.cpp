#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=300010;

int f(ll x){
    int res=0;
    int k=1;
    while(x){
        int r=x%2;
        res=res+r*k;
        k<<=1;
        x/=10;
    }
    return res;
}

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    map<int,int>mp;
    int t;
    cin>>t;
    while(t--){
        ll x;
        string cmd;
        cin>>cmd;
        if(cmd[0]=='+'){
            cin>>x;
            mp[f(x)]++;
        }else if(cmd[0]=='-'){
            cin>>x;
            mp[f(x)]--;
        }else{
            cin>>x;
            cout<<mp[f(x)]<<endl;
        }
    }
    return 0;
}