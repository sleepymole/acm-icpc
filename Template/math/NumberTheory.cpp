#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
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

int euler_phi(int n){
    int ans=n;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

int euler[maxn];
int getEuler(){
    euler[1]=1;
    for(int i=2;i<maxn;i++){
        if(!euler[i]){
            for(int j=i;j<maxn;j+=i){
                if(!euler[j]) euler[j]=j;
                euler[j]=euler[j]/i*(i-1);
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

int power_mod(int a,int n,int p){
    int r=1;
    while(n){
        if(n%2) r=(ll)r*a%p;
        a=(ll)a*a%p;
        n/=2;
    }
    return r;
}

//最小原根
int getPrimitiveRoot(int p){
    int n=getFactor(p-1);
    int x=-1;
    for(int x=2;x<p;x++){
        bool found=true;
        for(int i=0;i<n;i++){
            if(power_mod(x,(p-1)/factor[i][0],p)==1){
                found=false;break;
            }
        }
        if(found) return x;
    }
    return -1;
}

void initial(){
    getPrime();
    getEuler();
}
int main(){
    initial();
    int startTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    //TODO
    int endTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    cout<<(endTime-startTime)<<"ms"<<endl;
    return 0;
}