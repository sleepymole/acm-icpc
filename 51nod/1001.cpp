#include<iostream>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int k,n;
    cin>>k>>n;
    map<int,int>mp;
    int x;
    priority_queue<pii,vector<pii>,greater<pii> >ans;
    for(int i=0;i<n;i++){
        cin>>x;
        if(mp[k-x]){
            int y=k-x;
            if(x>y)swap(x,y);
            ans.push(make_pair(x,y));
        }else{
            mp[x]++;
        }
    }
    if(ans.empty()){
        cout<<"No Solution"<<endl;
    }else{
        while(!ans.empty()){
            pair<int,int>tmp=ans.top();
            ans.pop();
            cout<<tmp.first<<" "<<tmp.second<<endl;
        }
    }
    return 0;
}