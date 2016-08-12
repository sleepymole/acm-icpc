#include<cstring>
#include<cstdio>
const int maxn=1000010;
char str[maxn];

int main(){
    scanf("%s",str);
    int n=strlen(str);
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        if(str[i]=='1') sum2++;
    }
    int k=0;
    bool found=false;
    while(true){
        if(sum1==sum2){found=true;break;}
        if(k==n) break;
        if(str[k]=='0') sum1++;
        else sum2--;
        k++;
    }
    if(found) printf("%d\n",k);
    else printf("-1\n");
    return 0;
}