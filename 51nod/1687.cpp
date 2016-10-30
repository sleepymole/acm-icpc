#include<iostream>
#include<cstdio>
using namespace std;
const int N=100000;
int a[N+1],f[N+1],g[N+1];
int prime[N+1],mu[N+1];

int main(){
    mu[1]=1;
    for(int i=2;i<=N;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            g[i]+=a[j];
        }
    }
    while(q--){
        int A,i,b;
        scanf("%d",&A);
        if(A==1){
            scanf("%d%d",&i,&b);
            int t=b-a[i];a[i]=b;
            for(int d=1;d*d<=i;d++){
                if(i%d==0){
                    g[d]+=t;
                    if(d*d!=i) g[i/d]+=t;
                }
            }
        }else{
            scanf("%d",&i);
            int ans=0;
            for(int d=1;d*d<=i;d++){
                if(i%d==0){
                    if(d*d==i) ans+=mu[d]*g[d];
                    else ans+=mu[d]*g[d]+mu[i/d]*g[i/d];
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}