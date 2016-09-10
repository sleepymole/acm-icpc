#include<stdio.h>
typedef long long ll;
const int mod=1000000007;
int R[16],ans1,ans2,ans3;

int inverse(int a,int m){
    return a==1?1:(ll)inverse(m%a,m)*(m-m/a)%m;
}

int Combination(int n,int m){
    ll res=1,s=1;
    for(int i=0;i<m;i++){
        res=res*(n-i)%mod;
        s=s*(i+1)%mod;
    }
    return res*inverse(s,mod)%mod;
}

void cal(int m,int s){
    ans1=ans2=0;
    for(int i=0;i<(1<<m);i++){
        int cnt=0;
        int n=s;
        for(int j=0;j<m;j++){
            if((1<<j)&i){
                n-=R[j]+1;
                cnt++;
            }
        }
        if(n<0) continue;
        int c=Combination(n+m-1,m-1);
        if(cnt&1){
            ans1=(ans1-c)%mod;
            ans2=(ans2-(ll)n*c%mod*inverse(m,mod)%mod)%mod;
        }else{
            ans1=(ans1+c)%mod;
            ans2=(ans2+(ll)n*c%mod*inverse(m,mod)%mod)%mod;
        }
    }
    ans1=(ans1+mod)%mod;
    ans2=(ans2+mod)%mod;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int k,l,r,M=1,s=0,n=0;
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&l,&r);
            M=(ll)M*(r-l+1)%mod;
            R[n++]=r-l;
            s-=l;
        }
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&r,&l);
            M=(ll)M*(l-r+1)%mod;
            l*=-1;r*=-1;
            R[n++]=r-l;
            s-=l;
        }
        int inv=inverse(M,mod);
        cal(n,s);
        ans1=(ll)ans1*inv%mod;
        ans2=(ll)ans2*inv%mod;
        ans3=((1-ans1-ans2)%mod+mod)%mod;
        printf("%d %d %d\n",ans3,ans1,ans2);
    }
    return 0;
}