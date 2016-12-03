#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    vector<ll>s;
    ll x=1,y,z,limit=1e18;
    for(int i=0;i<64;i++){
        y=1;
        for(int j=0;j<50;j++){
            z=1;
            for(int k=0;k<50;k++){
                s.push_back(x*y*z);
                if(x*y*z<=limit/5) z*=5;
                else break;
            }
            if(x*y<=limit/3) y*=3;
            else break;
        }
        if(x<=limit/2) x*=2;
        else break;
    }
    sort(s.begin(),s.end());
    int t;
    cin>>t;
    while(t--){
        ll N;
        cin>>N;
        if(N==1) cout<<2<<endl;
        else cout<<*(lower_bound(s.begin(),s.end(),N))<<endl;
    }
    return 0;
}