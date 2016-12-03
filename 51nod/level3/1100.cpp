#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=10010;
struct Point{
    int x,y,id;
    Point(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator<(const Point& rhs) const{
        return x<rhs.x||(x==rhs.x&&y<rhs.y);
    }
}p[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
    }
    sort(p,p+n);
    vector<pair<int,int> >ans;
    int sx=p[1].x-p[0].x;
    int sy=p[1].y-p[0].y;
    ans.push_back(make_pair(p[0].id,p[1].id));
    for(int i=1;i<n-1;i++){
        int tx=p[i+1].x-p[i].x;
        int ty=p[i+1].y-p[i].y;
        ll c=(ll)sy*tx-(ll)sx*ty;
        if(c<0){
            ans.clear();
            sx=tx;sy=ty;
            ans.push_back(make_pair(p[i].id,p[i+1].id));
        }else if(c==0){ 
            ans.push_back(make_pair(p[i].id,p[i+1].id));
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
    return 0;
}