#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
typedef long long ll;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int n,x;
    map<int,int>mp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        mp[x]++;
    }
    if(mp.size()>3){
        cout<<"NO"<<endl;
    }else if(mp.size()<3){
        cout<<"YES"<<endl;
    }else{
        auto it=mp.begin();
        int a=(*it).first;
        it++;
        int b=(*it).first;
        it++;
        int c=(*it).first;
        if((a+c)!=2*b){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}