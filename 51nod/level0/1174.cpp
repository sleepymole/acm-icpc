#include<iostream>
#include<cstdio>
using namespace std;
int a[10010],n;
int d[10010][20];

void RMQ_init(){
    for(int i=0;i<n;i++) d[i][0]=a[i];
    for(int j=1;1<<j <=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int l,int r){
    int k=0;
    while(1<<(k+1) <= r-l+1)k++;
    return max(d[l][k],d[r-(1<<k)+1][k]);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    RMQ_init();
    int q,x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&x,&y);
        printf("%d\n",RMQ(x,y));
    }
    return 0;
}