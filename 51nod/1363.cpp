#include<stdio.h>

const int maxn=32000;
const int mod=1000000007;

int prime[maxn],factor[20][2],facCnt;
int ans;
void dfs(int pos,int num,int e){
    if(pos==facCnt){
        ans=(ans+1LL*num*e/2)%mod;
        return;
    }
    dfs(pos+1,num,e);
    for(int i=1;i<=factor[pos][1];i++){
        num*=factor[pos][0];
        e*=factor[pos][0]-(i==1?1:0);
        dfs(pos+1,num,e);
    }
}

int main(){
    for(int i=2;i<maxn;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
        }
        for(int j=1;j<=prime[0]&&i<maxn/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int x=n;
        facCnt=0;
        for(int i=1;i<=prime[0];i++){
            if(prime[i]>x/prime[i]) break;
                if(x%prime[i]==0){
                factor[facCnt][0]=prime[i];
                factor[facCnt][1]=0;
                while(x%prime[i]==0){
                    factor[facCnt][1]++;
                    x/=prime[i];
                }
                facCnt++;
            }
        }
        if(x>1){
            factor[facCnt][0]=x;
            factor[facCnt][1]=1;
            facCnt++;
        }
        ans=0;
        dfs(0,1,1);
        ans=1LL*(ans+1)*n%mod;
        printf("%d\n",ans);
    }
    return 0;
}