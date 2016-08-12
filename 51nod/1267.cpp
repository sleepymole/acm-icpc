#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1001;
int a[maxn];
struct Pair{
    int v,x,y;
    Pair(int _v=0,int _x=0,int _y=0):v(_v),x(_x),y(_y){}
    bool operator<(const Pair& rhs)const{
        return v<rhs.v;
    }
    bool operator==(const Pair& rhs)const{
        return rhs.x==x||rhs.x==y||rhs.y==x||rhs.y==y;
    }
}p[maxn*maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            p[k].v=a[i]+a[j];
            p[k].x=a[i];
            p[k].y=a[j];
            k++;
        }
    }
    sort(p,p+k);
    bool found=false;
    for(int i=0;i<k-1;i++){
        int pos=lower_bound(p+i+1,p+k,Pair(-p[i].v,0,0))-p;
        while(pos<k&&p[pos].v+p[i].v==0){
            if(!(p[pos]==p[i])){
                found=true;
                break;
            }
            pos++;
        }
        if(found) break;
    }
    if(found) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}