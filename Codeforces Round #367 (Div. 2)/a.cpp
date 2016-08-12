#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1001;
double d[maxn];
int main(){
    int a,b;
    cin>>a>>b;
    int n,x,y,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>v;
        d[i]=1.0*sqrt((x-a)*(x-a)+(y-b)*(y-b))/v;
    }
    sort(d,d+n);
    printf("%.10lf\n",d[0]);
    return 0;
}