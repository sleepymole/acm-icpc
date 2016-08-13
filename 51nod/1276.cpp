#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50010;
struct Island{
    int number,height;
    bool operator<(const Island& rhs)const{
        return height<rhs.height;
    }
}islands[maxn];
bool vis[maxn];
int a[maxn],res[maxn];
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        islands[i].number=i;
        islands[i].height=a[i];
        vis[i]=true;
    }
    sort(islands+1,islands+n+1);
    res[0]=1;
    for(int i=1;i<=n;i++){
        int x=islands[i].number;
        int h=islands[i].height;
        if(vis[x-1]&&vis[x+1]) res[i]=res[i-1]+1;
        else if((!vis[x-1])&&(!vis[x+1])) res[i]=res[i-1]-1;
        else res[i]=res[i-1];
        vis[x]=false;
    }
    while(q--){
        int x;
        cin>>x;
        int pos=upper_bound(islands+1,islands+n+1,(Island){0,x})-islands-1;
        cout<<res[pos]<<endl;
    }
    return 0;
}
