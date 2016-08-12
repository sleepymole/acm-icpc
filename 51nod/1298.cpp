#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

void format(ll &x){
    if(x>0) x=1;
    else if(x<0) x=-1;
}
bool check1(int x1,int y1,int x2,int y2,int r){
    ll d=(ll)(x2*y1-x1*y2)*(x2*y1-x1*y2);
    ll s=(ll)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*r*r;
    if(d>s) return false;
    ll a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    ll b=(ll)(x2*y1-x1*y2)*(y2-y1);
    if(x1==x2){
        if(y1*y2<=0) return true;
        else return false;
    }
    ll s1=a*x1+b;
    ll s2=a*x2+b;
    format(s1);format(s2);
    if(s1*s2<=0) return true;
    return false;
}
bool check(int xc,int yc,int r,int x1,int y1,int x2,int y2,int x3,int y3){
    x1-=xc;x2-=xc;x3-=xc;y1-=yc;y2-=yc;y3-=yc;
    ll a=r*r-x1*x1-y1*y1;
    ll b=r*r-x2*x2-y2*y2;
    ll c=r*r-x3*x3-y3*y3;
    if(a>0&&b>0&&c>0) return false;
    if(a*b<=0||a*c<=0||b*c<=0) return true;
    if(check1(x1,y1,x2,y2,r)) return true;
    if(check1(x1,y1,x3,y3,r)) return true;
    if(check1(x2,y2,x3,y3,r)) return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int xc,yc,r,x1,y1,x2,y2,x3,y3;
        cin>>xc>>yc>>r>>x1>>y1>>x2>>y2>>x3>>y3;
        if(check(xc,yc,r,x1,y1,x2,y2,x3,y3))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}