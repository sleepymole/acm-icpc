#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50010;
struct Segment{
    int x,y;
    Segment(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator<(const Segment& rhs)const{
        return x<rhs.x||(x==rhs.x&&y>rhs.y);
    }
}s[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].x>>s[i].y;
    }
    sort(s,s+n);
    int maxRight=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        if(s[i].x>maxRight) maxRight=s[i].y;
        else{
            if(s[i].y>maxRight){
                maxLen=max(maxLen,maxRight-s[i].x);
                maxRight=s[i].y;
            }else{
                maxLen=max(maxLen,s[i].y-s[i].x);
            }
        }
    }
    cout<<maxLen<<endl;
    return 0;
}