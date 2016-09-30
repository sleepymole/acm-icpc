#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=100010;
int a[maxn],c[maxn],n,x;
ll sum[maxn],k;
double tmp[maxn];

ll f(double t){
    fill(c+1,c+n+1,0);
    for(int i=0;i<=n;i++){
        tmp[i]=sum[i]-i*t;
    }
    sort(tmp,tmp+n+1);
    for(int i=0;i<=n;i++){
        a[i]=lower_bound(tmp,tmp+n+1,sum[i]-i*t)-tmp+1;
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
        for(int j=a[i]-1;j>=1;j-=j&-j) ans+=c[j];
        for(int j=a[i];j<=n;j+=j&-j) c[j]++;
    }
    return ans+1;
}

inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        x=read();
        sum[i]=sum[i-1]+x;
    }
    double l=0.0,r=100000.0,mid;
    while(r-l>1e-4){
        mid=(l+r)/2;
        if(f(mid)<=k) r=mid;
        else l=mid;
    }
    printf("%.4lf\n",r);
    return 0;
}