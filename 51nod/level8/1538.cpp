#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int P=104857601,G=3;
const int maxByte=17,N=1<<maxByte;

int inverse(int a,int p) {
    return a==1?1:(ll)inverse(p%a,p)*(p-p/a)%p;
}

int power_mod(int a,int n,int p) {
    int r=1;
    while(n){
        if(n%2) r=(ll)r*a%p;
        a=(ll)a*a%p;
        n/=2;
    }
    return r;
}

int wn[(maxByte<<1)+1];
void transform(int x[],int n,int on){
    for(int i=0,j=0;i<n;i++){
        if(i<j) swap(x[i],x[j]);
        for(int k=n>>1;(j^=k)<k;k>>=1);
    }
    for(int h=2,d=1;h<=n;h<<=1,d++){
        int e=wn[d+maxByte*(1-on)/2];
        for(int j=0;j<n;j+=h){
            int w=1;
            for(int k=j;k<j+h/2;k++){
                int u=x[k],t=(ll)w*x[k+h/2]%P;
                x[k]=(u+t)%P;
                x[k+h/2]=(u-t+P)%P;
                w=(ll)w*e%P;
            }
        }
    }
    if(on==-1){
        int inv=inverse(n,P);
        for(int i=0;i<n;i++){
            x[i]=(ll)x[i]*inv%P;
        }
    }
}

void polynomial_inverse(int a[],int b[],int n){
    static int tmp[N];
    int len=1;
    while(len<n) len<<=1;
    b[0]=inverse(a[0]%P,P);
    for(int h=2;h<=len;h<<=1){
        int p=h<<1;
        memcpy(tmp,a,h*sizeof(int));
        memset(tmp+h,0,h*sizeof(int));
        transform(b,p,1);
        transform(tmp,p,1);
        for(int i=0;i<p;i++){
            b[i]=(ll)(2LL-(ll)tmp[i]*b[i]%P+P)*b[i]%P;
        }
        transform(b,p,-1);
        memset(b+h,0,h*sizeof(int));
    }
    memset(b+n,0,(len-n)*sizeof(int));
}

int a[N],rev[N],base[N],tmp[N];
void polynomial_mod(int x[],int p,int len){
    static int d[N];
    bool flag=true;
    for(int i=len;i<p;i++){
        if(x[i]){
            flag=false;
            break;
        }
    }
    if(flag) return;
    for(int i=0;i<p;i++) d[i]=x[p-1-i];
    memset(d+p,0,p*sizeof(p));
    transform(d,p<<1,1);
    for(int i=0;i<(p<<1);i++){
        d[i]=(ll)d[i]*rev[i]%P;
    }
    transform(d,p<<1,-1);
    int t=p-len+1;
    reverse(d,d+t);
    memset(d+t,0,((p<<1)-t)*sizeof(int));
    transform(d,p,1);
    for(int i=0;i<p;i++){
        d[i]=(ll)d[i]*a[i]%P;
    }
    transform(d,p,-1);
    for(int i=0;i<len;i++){
        x[i]=(x[i]-d[i]+P)%P;;
    }
    memset(x+len,0,(p-len)*sizeof(int));
}

void pre_poly(int b[],int len,ll n){
    int p=1;
    while(p<(len<<1)) p<<=1;
    polynomial_inverse(a,rev,p-len+1);
    transform(rev,p<<1,1);
    reverse(a,a+len);
    transform(a,p,1);
    base[1]=b[0]=1;
    while(n){
        if(n%2){
            memcpy(tmp,base,p*sizeof(int));
            transform(b,p,1);
            transform(tmp,p,1);
            for(int i=0;i<p;i++){
                b[i]=(ll)b[i]*tmp[i]%P;
            }
            transform(b,p,-1);
            polynomial_mod(b,p,len);
        }
        transform(base,p,1);
        for(int i=0;i<p;i++){
            base[i]=(ll)base[i]*base[i]%P;
        }
        transform(base,p,-1);
        polynomial_mod(base,p,len);
        n>>=1;
    }
}

int b[N],f[N];
int main(){
    ll n,m;
    cin>>n>>m;
    int x,A,B;
    cin>>x>>A>>B;
    if(x>23333){
        x=((ll)A*x+B)%23333+1;
        n--;
    }
    a[0]=1;
    int len=0;
    for(int i=1;i<=n;i++){
        if(x+1>len) len=x+1;        
        a[x]=(a[x]+P-1)%P; x=(A*x+B)%23333+1;
    }
    for(int h=2,d=1;h<=N;h<<=1,d++){
        wn[d]=power_mod(G,(P-1)/h,P);
        wn[d+maxByte]=inverse(wn[d],P);
    }
    polynomial_inverse(a,f,len);
    pre_poly(b,len,m);
    int ans=0;
    for(int i=0;i<len;i++){
        ans=(ans+(ll)b[i]*f[i])%P;
    }
    cout<<ans<<endl;
    return 0;
}