#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=100010;
int prime[maxn/10],primeCnt;
bool notprime[maxn];

void getPrime(){
    notprime[0]=notprime[1]=true;
    for(int i=2;i<maxn;i++){
        if(!notprime[i]){
            prime[primeCnt++]=i;
            if(i>maxn/i) continue;
            for(int j=i*i;j<maxn;j+=i){
                notprime[j]=true;
            }
        }
    }
}

int factor[100][2];
int getFactor(ll x){
    int fatCnt=0;
    for(int i=0;i<primeCnt;i++){
        if(prime[i]>x/prime[i]) break;
        if(x%prime[i]==0){
            factor[fatCnt][0]=prime[i];
            factor[fatCnt][1]=0;
            while(x%prime[i]==0){
                factor[fatCnt][1]++;
                x/=prime[i];
            }
            fatCnt++;
        }
    }
    if(x>1){
        factor[fatCnt][0]=x;
        factor[fatCnt][1]=1;
        fatCnt++;
    }
    return fatCnt;
}

int ans,l,r,cnt;
void dfs(int num,int pos){
    if(num>r) return;
    if(pos==cnt){
        if(num%2==0&&num>=l&&num<=r) ans++;
        return;
    }
    int x=1;
    for(int i=0;i<=factor[pos][1];i++){
        if(num>r/x) break;
        dfs(num*x,pos+1);
        if(x>r/factor[pos][0]) break;
        x*=factor[pos][0];
    }
}

int main(){
    getPrime();
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(n%2){
            printf("0\n");
            continue;
        }
        l=(int)ceil(sqrt(2.0)*n);
        r=2*n-1;
        cnt=getFactor(n);
        for(int i=0;i<cnt;i++){
            factor[i][1]*=2;
        }
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}