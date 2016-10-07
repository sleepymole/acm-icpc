#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn=10000010;

int prime[maxn],euler[maxn];
int e[maxn],div_num[maxn];
void Sieve(){
    euler[1]=1; div_num[1]=1;
    for(int i=2;i<maxn;i++){
        if(!prime[i]){
            prime[++prime[0]]=i;
            euler[i]=i-1;
            e[i]=1; div_num[i]=2;
        }
        for(int j=1;j<=prime[0]&&prime[j]<maxn/i;j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                euler[i*prime[j]]=euler[i]*prime[j];
                div_num[i*prime[j]]=div_num[i]/(e[i]+1)*(e[i]+2);
            	e[i*prime[j]]=e[i]+1;
                break;
            }else{
                euler[i*prime[j]]=euler[i]*(prime[j]-1);
                div_num[i*prime[j]]=div_num[i]*div_num[prime[j]];
        		e[i*prime[j]]=1;
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

void getEuler(){
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

void initial(){
    Sieve();
}

void test(){

}

int main(){
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int startTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    initial();
    test();
    int endTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    cout<<(endTime-startTime)<<"ms"<<endl;
    return 0;
}