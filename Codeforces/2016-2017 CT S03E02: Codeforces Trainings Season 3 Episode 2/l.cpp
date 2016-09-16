#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    priority_queue<int>B,R;
    int S;
    cin>>S;
    for(int i=0;i<S;i++){
        string str;
        cin>>str;
        int n=str.length();
        int x=0;
        for(int j=0;j<n-1;j++){
            x=x*10+str[j]-'0';
        }
        if(str[n-1]=='R'){
            R.push(x);
        }else{
            B.push(x);
        }
    }
    int sum=0,cnt=0;
    while(!R.empty()&&!B.empty()){
        sum+=R.top()+B.top();
        R.pop();B.pop();
        cnt++;
    }
    sum-=cnt*2;
    cout<<sum<<endl;
    return 0;
}