#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int n,r,cnt,ans;
int seven[30]={48,192,432,768,1224,1740,2356,
    3102,3954,4896,5872,6960,8280,9564,11016,12456,
    14160,15816,17666,19584,21500,23688,25808,28122,
    30624,33120,35664,38266,41200,44076};
struct Point{
    int x,y;
    Point(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator<(const Point& rhs)const{
        return (x*x+y*y)>(rhs.x*rhs.x+rhs.y*rhs.y);
    }
}p[200],s[10];

void dfs(int pre,int pos){
    if(pos==n){
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum+=(s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y);
            }
        }
        if(sum>ans) ans=sum;
        return;
    }
    for(int i=pre;i<cnt;i++){
        s[pos]=p[i];
        dfs(i,pos+1);
    }
}

int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

void write(int n){
    if(n>=10)write(n/10);
    putchar(n%10+'0');
}

int main(){
    int t=read();
    while(t--){
        n=read();
        r=read();
        if(n%2==0){
            write(n*n*r*r);
            putchar('\n');
            continue;
        }
        if(n==7){
            write(seven[r-1]);
            putchar('\n');
            continue;
        }
        ans=0;cnt=0;
        for(int i=-r;i<=r;i++){
            for(int j=-r;j<=r;j++){
                if((i*i+j*j<=r*r)&&(i*i+j*j>(r-1)*(r-1))){
                    p[cnt++]=Point(i,j);
                }
            }
        }
        sort(p,p+cnt);
        cnt=min(cnt,150/n);
        dfs(0,0);
        write(ans);
        putchar('\n');
    }
    return 0;
}