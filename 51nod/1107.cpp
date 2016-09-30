#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=50010;
int a[maxn],n;

struct Point{
    int x,y;
    bool operator<(const Point& rhs)const{
        return x==rhs.x?y<rhs.y:x<rhs.x;
    }    
}p[maxn];

void add(int x,int v){
    for(int i=x;i<=n;i+=i&-i){
        a[i]+=v;
    }
}

int sum(int x){
    int s=0;
    for(int i=x;i>=1;i-=i&-i){
        s+=a[i];
    }
    return s;
}

int main(){
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        a[i]=p[i].y;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        p[i].y=lower_bound(a,a+n,p[i].y)-a+1;
    }
    fill(a,a+n,0);
    int ans=0;
    for(int i=0;i<n;i++){
        add(p[i].y,1);
        ans+=i+1-sum(p[i].y);
    }
    printf("%d\n",ans);
    return 0;
}