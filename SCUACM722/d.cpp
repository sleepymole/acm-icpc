#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
double f[maxn];
//int a[1000];
double dfs(int n){
    if(n==1) return 0.0;
    else if(f[n]>0.0) return f[n];
    int cnt=0;
    int a[1000];
    //memset(a,0,sizeof(a));
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            a[cnt++]=i;
            if(i*i!=n) a[cnt++]=n/i;
        }
    }
    double s=1.0;
    for(int i=0;i<cnt;i++){
        if(a[i]==1) continue;
        s+=dfs(n/a[i])/cnt;
    }
    s=s*cnt/(cnt-1);
    f[n]=s;
    return s;
}
int main(){
    // freopen("input","r",stdin);
    // freopen("output1","w",stdout);
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++){
        int n;
        cin>>n;
        printf("Case %d: %.10lf\n",ca,dfs(n));
    }
    return 0;
}