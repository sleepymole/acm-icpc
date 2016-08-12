#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,x;
		cin>>n>>m;
		int count=0;
		for(int i=0;i<n*m;i++){
			cin>>x;
			if(x==1) count++;
		}
		if(count%2==1) cout<<"yadang"<<endl;
		else cout<<"xiawa"<<endl;
	}
	return 0;
}