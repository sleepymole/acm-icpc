#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
int pa[201],f[201];
bool vis[201];

int findset(int x){
    return x==pa[x]?x:pa[x]=findset(pa[x]);
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        pa[i]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
        int x=findset(i);
        int y=findset(f[i]);
        if(x!=y){
            pa[x]=y;
        }
    }
    queue< set<int> >q;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        set<int>s;
        s.insert(i);
        for(int j=i+1;j<=n;j++){
            int x=findset(i);
            int y=findset(j);
            if(x==y){
                s.insert(j);
                vis[j]=true;
            }
        }
        q.push(s);
    }
    vector<int>b;
    vector<int>c;
    memset(vis,false,sizeof(vis));
    while(!q.empty()){
        set<int>s=q.front();q.pop();
        map<int,int>mp;
        int x=(*s.begin());
        mp[x]=1;
        while(!mp[f[x]]){
            x=f[x];mp[x]=1;
        }
        vis[x]=true;
        int k=1;
        x=f[x];
        while(!vis[x]){
            vis[x]=true;
            k++;x=f[x];
        }
        c.push_back(k);
        set<int>::iterator it=s.begin();
        for(;it!=s.end();it++){
            if(vis[*it]) continue;
            x=(*it);
            int br=1;
            x=f[x];
            while(!vis[x]){
                br++;x=f[x];
            }
            b.push_back(br);
        }
    }
    ll ans=1;
    int sz=c.size();
    for(int i=0;i<sz;i++){
        ans=ans*(c[i]/gcd(ans,c[i]));
    }
    ll t=ans;
    sz=b.size();
    for(int i=0;i<sz;i++){
        if(b[i]>ans){
            if(b[i]%t==0){
                if(b[i]>ans) ans=b[i];
            }else{
                if((b[i]/t+1)*t>ans) ans=(b[i]/t+1)*t;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}