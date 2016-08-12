#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10001;
struct Segment{
    int s,e;
    Segment(int _s=0,int _e=0):s(_s),e(_e){}
    bool operator<(const Segment& rhs)const{
        return e<rhs.e||(e==rhs.e&&s<rhs.s);
    }
}s[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].s>>s[i].e;
    }
    sort(s,s+n);
    int ans=1,maxRight=s[0].e;
    for(int i=1;i<n;i++){
        if(s[i].s>=maxRight){
            ans++;
            maxRight=s[i].e;
        }
    }
    cout<<ans<<endl;
    return 0;
}