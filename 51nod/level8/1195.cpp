#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

int P;
struct Matrix{
    int mat[2][2];
    Matrix operator*(const Matrix& rhs)const{
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    res.mat[i][j]=(res.mat[i][j]+(ll)mat[i][k]*rhs.mat[k][j])%P;
                }
            }
        }
        return res;
    }
    Matrix operator^(int n)const{
        Matrix a=(*this);
        Matrix res;
        memset(res.mat,0,sizeof(res.mat));
        res.mat[0][0]=res.mat[1][1]=1;
        while(n){
            if(n%2) res=res*a;
            a=a*a;
            n/=2;
        }
        return res;
    }
    bool operator==(const Matrix &rhs)const{
        return memcmp(mat,rhs.mat,sizeof(mat))==0;
    }
}A={0,1,1,1},I={1,0,0,1};

int power_mod(int a,int n,int p){
    int r=1;
    while(n){
        if(n&1) r=(ll)r*a%p;
        a=(ll)a*a%p;
        n>>=1;
    }
    return r;
}

bool witness(int a,int p){
    int q=p-1,k=0;
    while(q%2==0){
        q>>=1;k++;
    }
    int v=power_mod(a,q,p);
    if(v==1||v==p-1) return false;
    while(k--){
        v=(ll)v*v%p;
        if(v==1||v==p-1) return false;
    }
    return true; 
}

bool miller_rabin(int n){
    if(n==2) return true;
    if(n==1||n%2==0) return false;
    for(int i=0;i<20;i++){
        int a=rand()%(n-1)+1;
        if(witness(a,n)) return false;
    }
    return true;
}

int pollard_rho(int n){
    int k=2,x0=1,y=x0;
    int c=rand()%(n-1)+1;
    for(int i=2;;i++){
        x0=((ll)x0*x0+c)%n;
        int s=__gcd(abs(y-x0),n);
        if(s!=1&&s!=n) return s;
        if(y==x0) return n;
        if(i==k) y=x0,k<<=1;
    }
}

vector<int>v;
void factor(int n){
    if(miller_rabin(n)){
        v.push_back(n);
        return;
    }
    int d=n;
    while(d==n) d=pollard_rho(n);
    factor(d);
    factor(n/d);
}

int fac[100][2],cnt;
void getProduct(int n){
    v.clear();cnt=0;
    memset(fac,0,sizeof(fac));
    if(n==1) return;
    factor(n);
    sort(v.begin(),v.end());
    vector<int>::iterator it=v.begin();
    while(it!=v.end()){
        fac[cnt][0]=*it;
        while(it!=v.end()&&*it==fac[cnt][0]){
            fac[cnt][1]++; it++;
        }
        cnt++;
    }
}

unordered_map<int,int>Hash;
int repetend(int p){
    if(Hash.count(p)) return Hash[p];
    int n=power_mod(5,(p-1)>>1,p)==1?p-1:(p+1)<<1;
    P=p;
    int ret=n;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            while(ret%i==0&&(A^(ret/i))==I) ret/=i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1&&(A^(ret/n))==I) ret/=n;
    return Hash[p]=ret;
}

int main(){
    int T;
    scanf("%d",&T);
    Hash[2]=3;Hash[5]=20;
    while(T--){
        int n;
        scanf("%d",&n);
        getProduct(n);
        ll ans=1;
        for(int i=0;i<cnt;i++){
            ll r=repetend(fac[i][0]);
            for(int j=1;j<fac[i][1];j++) r*=fac[i][0];
            ans=ans/__gcd(ans,r)*r;
        }
        printf("%lld\n",ans);
    }
    return 0;
}