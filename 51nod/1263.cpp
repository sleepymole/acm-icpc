#include<string.h>
#include<stdio.h>
typedef long long ll;
const int N=31622;
int prime[N+1];

int power_mod(int a,int n,int p){
    int r=1;
    while(n){
        if(n&1) r=(ll)r*a%p;
        a=(ll)a*a%p;
        n>>=1;
    }
    return r;
}

int P,A,B;
struct Poly{
    int data[4];
    Poly(){memset(data,0,sizeof(data));}
    Poly operator*(const Poly& rhs)const{
        Poly res;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                res.data[i+j]=(res.data[i+j]+(ll)data[i]*rhs.data[j])%P;
            }
        }
        res.data[2]=(res.data[2]+(ll)A*res.data[3])%P;
        res.data[1]=(res.data[1]+(ll)B*res.data[3])%P;
        res.data[1]=(res.data[1]+(ll)A*res.data[2])%P;
        res.data[0]=(res.data[0]+(ll)B*res.data[2])%P;
        return res;
    }
};

bool isRe(ll n){
    Poly X,Y;
    X.data[0]=Y.data[1]=1;
    while(n){if(n&1) X=X*Y;Y=Y*Y; n>>=1;}
    int x=(X.data[0]+X.data[1])%P;
    Y.data[0]=0;Y.data[1]=1;X=X*Y;
    int y=(X.data[0]+X.data[1])%P;
    return x==1&&y==1;
}

ll repetend(int p,int k){
    int n=1;
    for(int i=0;i<k;i++) n*=p;
    int delta=((ll)A*A+4LL*B)%p,x=p-1,y=n/p;
    if(p==2) x=n,y=3;
    else if(delta==0) y*=p;
    else if(power_mod(delta,(p-1)>>1,p)!=1) y*=(p+1);
    ll ret=(ll)x*y;P=n;
    if(!isRe(ret)) return -1;
    for(int i=1;i<=prime[0];i++){
        if(x/prime[i]<prime[i]&&y/prime[i]<prime[i]) break;
        if(x%prime[i]==0){
            while(ret%prime[i]==0&&isRe(ret/prime[i])) ret/=prime[i];
            while(x%prime[i]==0) x/=prime[i];
        }
        if(y%prime[i]==0){
            while(ret%prime[i]==0&&isRe(ret/prime[i])) ret/=prime[i];
            while(y%prime[i]==0) y/=prime[i];
        }
    }
    if(x>1&&isRe(ret/x)) ret/=x;
    if(y>1&&isRe(ret/y)) ret/=y;
    return ret;
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    for(int i=2;i<=N;i++){
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&i<=N/prime[j];j++){
            prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d%d%d",&A,&B,&n);
        ll ans=1,r;
        for(int i=1;i<=prime[0];i++){
            if(n/prime[i]<prime[i]) break;
            if(n%prime[i]==0){
                int k=0;
                while(n%prime[i]==0) n/=prime[i],k++;
                r=repetend(prime[i],k);
                if(r==-1){ans=-1;break;}
                ans=ans/gcd(ans,r)*r;
            }
        }
        if(ans!=-1&&n>1){
            r=repetend(n,1);
            if(r==-1) ans=-1;
            else ans=ans/gcd(ans,r)*r;
        }
        printf("%lld\n",ans);
    }
    return 0;
}