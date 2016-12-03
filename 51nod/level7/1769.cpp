#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int maxn=500010;
char str[maxn*2];
int n,k,tmp[maxn];;

void init(){
    scanf("%d%s",&n,str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        k=((ll)k*10+str[i]-'0')%mod;
    }
}

void calc(int f[],int g[],int h[]){
    for (int i=1;i*i<=n;i++)
        for (int j=i;i*j<=n;j++)
            if(j==i) h[i*j]=(h[i*j]+(ll)f[i]*g[j]%mod)%mod;
            else h[i*j]=(h[i*j]+(ll)f[i]*g[j]%mod+(ll)f[j]*g[i]%mod)%mod;
}

void power_dirichlet(int f[],int g[],int k){
    g[1]=1;
    while(k){
        if(k%2){
            for(int i=1;i<=n;i++){
                tmp[i]=g[i];
                g[i]=0;
            }
            calc(f,tmp,g);
            
        }
        memset(tmp,0,sizeof(tmp));
        calc(f,f,tmp);
        copy(tmp,tmp+1+n,f);
        k/=2;
    }
}

int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

int f[maxn],g[maxn];
int main(){
    init();
    fill(f+1,f+n+1,1);
    power_dirichlet(f,g,k);
    for(int i=1;i<=n;i++){
        f[i]=read();
    }
    fill(tmp+1,tmp+1+n,0);
    calc(f,g,tmp);
    for(int i=1;i<=n;i++){
        printf("%d ",tmp[i]);
    }
    printf("\n");
    return 0;
}