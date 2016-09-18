#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int n,c;
    cin>>n>>c;
    int pre=-c-10,t,cnt=0;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t-pre<=c){
            cnt++;
            pre=t;
        }else{
            cnt=1;
            pre=t;
        }
    }
    cout<<cnt<<endl;
    return 0;
}