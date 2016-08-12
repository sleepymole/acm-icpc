#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1000010;
int a[maxn];
void build(int o,int l,int r){
    if(l==r){scanf("%d",&a[o]);return;}
    int mid=(l+r)/2;
    build(2*o+1,l,mid);
    build(2*o+2,mid+1,r);
    a[o]=max(a[2*o+1],a[2*o+2]);
}
void update(int o,int l,int r,int p,int v){
    if(l==r){a[o]=v;return;}
    int mid=(l+r)/2;
    if(p<=mid) update(2*o+1,l,mid,p,v);
    else update(2*o+2,mid+1,r,p,v);
    a[o]=max(a[2*o+1],a[2*o+2]);
}
int query(int o,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return a[o];
    int mid=(l+r)/2;
    int ans=0;
    if(ql<=mid) ans=max(ans,query(2*o+1,l,mid,ql,qr));
    if(qr>mid) ans=max(ans,query(2*o+2,mid+1,r,ql,qr));
    return ans;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        build(0,0,n-1);
        char cmd[5];
        int x,y;
        while(m--){
            scanf("%s%d%d",cmd,&x,&y);
            if(cmd[0]=='Q') printf("%d\n",query(0,0,n-1,x-1,y-1));
            else update(0,0,n-1,x-1,y);
        }
    }
    return 0;
}