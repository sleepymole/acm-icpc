#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int sumv[maxn],setv[maxn];

void update(int o,int l,int r,int sl,int sr,int v){
    if(sr<l||sl>r) return;
    if(sl<=l&&r<=sr){
        setv[o]=v; return;
    }
    if(setv[o]>=0){
        setv[2*o+1]=setv[o];
        setv[2*o+2]=setv[o];
        setv[o]=-1;
    }
    int mid=(l+r)/2;
    if(sl<=mid) update(2*o+1,l,mid,sl,sr,v);
    if(sr>mid) update(2*o+2,mid+1,r,sl,sr,v);
    sumv[o]=0;
    sumv[o]+=setv[2*o+1]>=0?(mid-l+1)*setv[2*o+1]:sumv[2*o+1];
    sumv[o]+=setv[2*o+2]>=0?(r-mid)*setv[2*o+2]:sumv[2*o+2];
}
int query(int o,int l,int r,int ql,int qr){
    if(ql>qr) return 0;
    if(setv[o]>=0) return (qr-ql+1)*setv[o];
    if(l==ql&&r==qr) return sumv[o];
    int mid=(l+r)/2;
    return query(2*o+1,l,mid,ql,qr>mid?mid:qr)+
            query(2*o+2,mid+1,r,ql<mid+1?mid+1:ql,qr);
}
int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(sumv,0,sizeof(sumv));
        memset(setv,-1,sizeof(setv));
        int n,m,k,a,b;
        cin>>n>>m;
        while(m--){
            cin>>k>>a>>b;
            if(k==1){
                int ms=query(0,0,n-1,a,n-1);
                if(ms==(n-a)){
                    cout<<"Can not put any one."<<endl;
                    continue;
                }
                int first,last;
                if(query(0,0,n-1,a,a)==0){
                    first=a;
                }else{
                    int l=a,r=n-1;
                    while(r-l>1){
                        int mid=(l+r)/2;
                        if((mid-a+1-query(0,0,n-1,a,mid))==0) l=mid;
                        else r=mid;
                    }
                    first=r;
                }
                if((n-a-ms)>b){
                    int l=first,r=n-1;
                    while(r-l>1){
                        int mid=(l+r)/2;
                        if((mid-first+1-query(0,0,n-1,first,mid))>=b) r=mid;
                        else l=mid;
                    }
                    if((l-first+1-query(0,0,n-1,first,l))==b) last=l;
                    else last=r;
                }else{
                    if(query(0,0,n-1,n-1,n-1)==0) last=n-1;
                    else{
                        int l=first,r=n-1;
                        while(r-l>1){
                            int mid=(l+r)/2;
                            if((n-mid-query(0,0,n-1,mid,n-1))==0) r=mid;
                            else l=mid;
                            last=l;
                        }
                    }
                }
                update(0,0,n-1,first,last,1);
                cout<<first<<" "<<last<<endl;
            }else{
                cout<<query(0,0,n-1,a,b)<<endl;
                update(0,0,n-1,a,b,0);
            }
        }
        cout<<endl;
    }
    return 0;
}