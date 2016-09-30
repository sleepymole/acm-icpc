#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=200010;
ll a[maxn];

struct Node{
    int id;
    long long v;
    Node(int i=0,ll _v=0):id(i),v(_v){}
    bool operator<(const Node& rhs)const{
        return v>rhs.v;
    }
};

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    ll n,k,x;
    cin>>n>>k>>x;
    int cnt=0;
    vector<int>v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<0) cnt++;
        if(a[i]==0){
            v.push_back(i);
        }
    }
    int sz=v.size();
    if(sz){
        if(sz>k){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            printf("\n");
            return 0;
        }
        for(int i=1;i<(int)v.size();i++){
            a[v[i]]=x;
        }
        if(cnt%2) a[v[0]]=x;
        else a[v[0]]=-x;
        k-=sz;
        cnt=1;
    }
    if(cnt%2){
        priority_queue<Node>q;
        for(int i=1;i<=n;i++){
            q.push(Node(i,abs(a[i])));
        }
        for(int i=0;i<k;i++){
            Node tmp=q.top();q.pop();
            tmp.v+=x;
            q.push(tmp);
        }
        while(!q.empty()){
            Node tmp=q.top();q.pop();
            if(a[tmp.id]<0) a[tmp.id]=-tmp.v;
            else a[tmp.id]=tmp.v;
        }
    }else{
        ll minc=0x3f3f3f3f;
        int p=-1;
        for(int i=1;i<=n;i++){
            int v=abs(a[i]);
            if(v<minc){
                minc=v;
                p=i;
            }
        }
        if((ll)k*x<=minc){
            if(a[p]<0) a[p]=(ll)k*x-minc;
            else a[p]=minc-(ll)k*x;
        }else{
            k-=minc/x+1;
            minc-=x*(minc/x+1);
            if(a[p]>0) a[p]=minc;
            else a[p]=-minc;
            priority_queue<Node>q;
            for(int i=1;i<=n;i++){
                q.push(Node(i,abs(a[i])));
            }
            for(int i=0;i<k;i++){
                Node tmp=q.top();q.pop();
                tmp.v+=x;
                q.push(tmp);
            }
            while(!q.empty()){
                Node tmp=q.top();q.pop();
                if(a[tmp.id]<0) a[tmp.id]=-tmp.v;
                else a[tmp.id]=tmp.v;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    printf("\n");
    return 0;
}
