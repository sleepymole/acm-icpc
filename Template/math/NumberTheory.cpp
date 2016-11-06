#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100000;

int prime[N+1];
void pre(){
    for(int i=2;i<=N;i++){
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int euler[N+1],mu[N+1];
void pre2(){
    euler[1]=mu[1]=1;
    for(int i=2;i<=N;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            euler[i]=i-1;
            mu[i]=-1;
        }
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                euler[i*prime[j]]=euler[i]*prime[j];
                mu[i*prime[j]]=0;
                break;
            }else{
                euler[i*prime[j]]=euler[i]*(prime[j]-1);
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}

int getEuler(int n){
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


int factor[100][2];
int getFactor(ll x){
    int fatCnt=0;
    for(int i=1;i<=prime[0];i++){
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

int power_mod(int a,int n,int p){
    int r=1;
    while(n){
        if(n%2) r=(ll)r*a%p;
        a=(ll)a*a%p;
        n/=2;
    }
    return r;
}

int getPrimitiveRoot(int p){
    int n=getFactor(p-1);
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

int main(){
    pre();
    cin.get();
    return 0;
}