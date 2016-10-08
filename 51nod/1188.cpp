#include<stdio.h>
#include<math.h>
const int maxn=5000010;

int euler[maxn];
long long sum[maxn];
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

void initial(){
    getEuler();
    for(int i=1;i<maxn;i++){
        sum[i]=sum[i-1]+euler[i];
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

void write(long long n){
    if(n>=10)write(n/10);
    putchar(n%10+'0');
}

int main(){
    initial();
    int T;
    scanf("%d",&T);
    while(T--){
        int n=read();
        long long ans=0;
        int r=sqrt(n);
        for(int i=1;i<=r;i++){
            ans+=sum[i]*(n/i+n/(i+1)+1)*(n/i-n/(i+1))/2+i*sum[n/i];
        }
        if(n<r*(r+1)) ans-=r*sum[n/r];
        ans-=(long long)n*(n+1)/2;
        write(ans);
        putchar('\n');
    }
    return 0;
}