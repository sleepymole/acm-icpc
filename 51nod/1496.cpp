#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	ll l,r,k;
	cin>>l>>r>>k;
	if(k>=4){
        if(l+3<r||((l+3==r)&&(l%2==0))){
            cout<<0<<endl;
            return 0;
        }
    }
	if(k>=3){
        int t=0;
        while(l>>t) t++;
        ll k=3LL<<(t-1);
        if(k<=r){
            cout<<0<<endl;
            return 0;
        }
	}
	if(k>=2){
		if(l%2==0||l+1<r){cout<<1<<endl;return 0;}
        else if((l^r)<l){cout<<(l^r)<<endl;return 0;}
	}
    if(k>=1){
        cout<<l<<endl;
    }
	return 0;
}