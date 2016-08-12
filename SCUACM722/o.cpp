#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int a[maxn],n;
void add(int x,int y){
    for(int i=x;i<=n;i+=i&(-i)) a[i]+=y;
}
int sum(int x){
    int ans=0;
    for(int i=x;i>0;i-=i&(-i)) ans+=a[i];
    return ans;
}
int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        memset(a,0,sizeof(a));
        cin>>n;
        int x,y;
        for(int i=1;i<=n;i++){
            scanf("%d",&y);
            add(i,y);
        }
        char cmd[10];
        printf("Case %d:\n",ca);
        while(scanf("%s",cmd)!=EOF){
            if(cmd[0]=='E') break;
            scanf("%d%d",&x,&y);
            if(cmd[0]=='A')add(x,y);
            else if(cmd[0]=='S')add(x,-y);
            else printf("%d\n",sum(y)-sum(x-1));
        }
    }
    return 0;
}