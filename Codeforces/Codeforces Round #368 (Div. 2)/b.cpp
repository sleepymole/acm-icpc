#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int maxn=100010;
const int INF=0x3f3f3f3f;
struct Edge{
    int to,dist;
};
vector<Edge>s[maxn];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,l;
    while(m--){
        cin>>u>>v>>l;
        s[u].push_back((Edge){v,l});
        s[v].push_back((Edge){u,l});
    }
    int ans=INF;
    int x;
    map<int,int>mp;
    while(k--){
        cin>>x;
        mp[x]++;
    }
    for(int i=1;i<=n;i++){
        if(mp[i]==0) continue;
        int sz=s[i].size();
        for(int j=0;j<sz;j++){
            if(!mp[s[i][j].to]){
                ans=min(ans,s[i][j].dist);
            }
        }
    }
    if(ans<INF) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}