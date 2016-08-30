#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=10010;

struct Point{
    int x,w;
    bool operator<(const Point& rhs)const{
        return x<rhs.x;
    }
}p[maxn];

int main(){
    int n;
    ll sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].x,&p[i].w);
        sum+=p[i].w;
    }
    sort(p,p+n);
    ll mid=sum/2;
    sum=0;
    int x=-1;
    for(int i=0;i<n;i++){
        sum+=p[i].w;
        if(sum>mid){
            x=i;
            break;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(ll)p[i].w*abs(p[i].x-p[x].x);
    }
    cout<<ans<<endl;
    return 0;
}