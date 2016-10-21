#include<cstdio>
#include<cstring>
const int maxn=1000010;
char str[maxn];
int sum[maxn];

int main(){
    scanf("%s",str);
    int n=strlen(str);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(str[i-1]=='1'?1:-1);
    }
    int Min=maxn+10,p=-1;
    for(int i=1;i<n;i++){
        if(sum[i-1]>sum[i]&&sum[i+1]>sum[i]&&sum[i]<Min){
            p=i;Min=sum[i];
        }
    }
    if(p==-1) printf("0\n");
    else{
        int l=0,r=n;
        for(;l<p;l++){
            if(sum[l]>Min) break;
        }
        for(;r>p;r--){
            if(sum[r]>Min) break;
        }
        printf("%d\n",r-l);
    }
    return 0;
}