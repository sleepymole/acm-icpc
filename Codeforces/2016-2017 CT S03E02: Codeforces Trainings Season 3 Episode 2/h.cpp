#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100010;
bool vis[maxn];
char str[maxn];

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int k;
    cin>>k;
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(str[i]=='0') continue;
        for(int j=i;j<=n;j+=k){
            vis[j]=true;
            if(str[j+1]=='1'){
                cout<<i<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<0<<" "<<0<<endl;
    return 0;
}