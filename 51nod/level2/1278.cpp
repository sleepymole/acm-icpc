#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=50001;
struct Segment{
    int s,e;
    Segment(int _s=0,int _e=0):s(_s),e(_e){}
    bool operator<(const Segment& rhs)const{
        return s<rhs.s||(s==rhs.s&&e<rhs.e);
    }
}s[maxn];

int main(){
    int n;
    cin>>n;
    int x,r;
    for(int i=0;i<n;i++){
        cin>>x>>r;
        s[i].s=x-r;s[i].e=x+r;
    }
    sort(s,s+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[n-1].s>s[i].e){
            int l=i,r=n-1;
            while(r-l>1){
                int mid=(l+r)/2;
                if(s[mid].s>s[i].e) r=mid;
                else l=mid;
            }
            ans+=n-r;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}