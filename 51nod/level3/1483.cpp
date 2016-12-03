#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
const int maxn=100010;
int a[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=a[0];
    for(int i=1;i<n;i++){
        stack<int>s,q;
        while(x) s.push(x%2),x/=2;
        int tmp=a[i];
        while(tmp) q.push(tmp%2),tmp/=2;
        while((!s.empty())&&(!q.empty())&&(s.top()==q.top())){
            x=(x<<1)+s.top();
            s.pop();q.pop();
        }
    }
    int ans=0;
    map<int,int>mp;
    for(int i=0;i<20;i++){
        if(x*(1<<i)>(1<<20)) break;
        mp[x*(1<<i)]=1;
    }
    for(int i=0;i<n;i++){
        while(!mp[a[i]]){
            a[i]/=2;
            ans++;
        }
        a[i]/=x;
    }
    mp.clear();
    for(int i=0;i<20;i++){
        mp[1<<i]=i;
    }
    for(int i=0;i<n;i++){
        a[i]=mp[a[i]];
    }
    sort(a,a+n);
    int mid=a[n/2];
    for(int i=0;i<n;i++){
        if(a[i]>mid) ans+=a[i]-mid;
        else ans+=mid-a[i];
    }
    cout<<ans<<endl;
    return 0;
}