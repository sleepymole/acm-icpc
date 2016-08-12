#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const double inf=1e10;
const double eps=1e-10;
const int maxn=110;
double x[maxn],y[maxn],z[maxn],r[maxn];
double dist[maxn][maxn],lowc[maxn];
bool vis[maxn];

double Prim(int n){
    double ans=0.0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<n;i++){
        lowc[i]=dist[0][i];
    }
    for(int i=1;i<n;i++){
        double minc=inf;
        int p=-1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&minc>lowc[j]){
                p=j;minc=lowc[j];
            }
        }
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;j++){
            if(!vis[j]&&lowc[j]>dist[p][j]){
                lowc[j]=dist[p][j];
            }
        }
    }
    return ans;
}
int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int n;
    while(cin>>n,n!=0){
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>z[i]>>r[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double d=sqrt((x[i]-x[j])*(x[i]-x[j])
                +(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))-r[i]-r[j];
                if(d<0.0||fabs(d)<eps) dist[i][j]=0.0;
                else dist[i][j]=d;
            }
        }
        printf("%.3lf\n",Prim(n));
    }
    return 0;
}