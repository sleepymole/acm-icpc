#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=50010;

struct Task{
    int e,w;
    bool operator<(const Task& rhs)const{
        return e<rhs.e;
    }
}task[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>task[i].e>>task[i].w;
    }
    sort(task,task+n);
    priority_queue<int,vector<int>, greater<int> >q;
    for(int i=0;i<n;i++){
        if(task[i].e>q.size()) q.push(task[i].w);
        else{
            if(task[i].w>q.top()){
                q.pop();q.push(task[i].w);
            }
        }
    }
    ll ans=0;
    while(!q.empty()){
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;
    return 0;
}