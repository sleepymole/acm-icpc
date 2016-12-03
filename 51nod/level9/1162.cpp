#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<ctime>
using namespace std;
typedef __int128 int128;

int128 read(){
    int128 x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

void write(int128 n){
    if(n>=10)write(n/10);
    putchar(n%10+'0');
}

int128 multiply_mod(int128 x,int128 y,int128 p){
    int128 r=0;
    while(y){
        if(y&1){r+=x; if(r>=p) r-=p;}
        x+=x; if(x>=p) x-=p;
        y>>=1;
    }
    return r;
}

int128 power_mod(int128 a,int128 n,int128 p){
    int128 r=1;
    while(n){
        if(n%2) r=multiply_mod(r,a,p);
        a=multiply_mod(a,a,p);
        n/=2;
    }
    return r;
}

bool witness(int128 a,int128 p){
    int128 q=p-1,k=0;
    while(q%2==0){
        k++;q/=2;
    }
    int128 v=power_mod(a,q,p);
    if(v==1||v==p-1) return false;
    while(k--){
        v=multiply_mod(v,v,p);
        if(v==p-1) return false;
    }
    return true;
}

bool miller_rabin(int128 p){
    if(p==2) return true;
    if(p==1||p%2==0) return false;
    for(int i=0;i<50;i++){
        int128 a=rand()%(p-1)+1;
        if(witness(a,p)) return false;
    }
    return true;
}

inline int128 abs(int128 x){
    return x>0?x:-x;
}

int128 gcd(int128 x,int128 y){
    while(y!=0){ x%=y; swap(x,y);}
    return x;
}


int128 pollard_rho(int128 n,int c){
    int128 i=1,k=2,x0=1,y=x0;
    while(true){
        i++;
        x0=multiply_mod(x0,x0,n)+c;
        if(x0>=n) x0-=n;
        int128 s=gcd(abs(y-x0),n);
        if(s!=1&&s!=n) return s;
        if(y==x0) return n;
        if(i==k) y=x0,k<<=1;
    }
}

int f[25]={0xdc9438b,0x466141b5,0xdff4d6,0x27e90edd,
    0x37fee414,0x636c4f52,0x6e6314a7,0x10e79416,
    0x3cb493b8,0x49a27bc9,0x3203edec,0x421a0348,
    0x68e8d894,0x1146b085,0x5c992e21,0x720b3c9b,
    0x71f2926a,0x48917ced,0x26dadb4d,0x59c0e2fb,
    0x64da7ada,0x507a55f1,0x337131b1,0x3c7235c,
    0x32ddb0e
};

int h[25]={0x25,0x35,0x2a,0x29,0x26,0x57,0x44,
    0x4f,0x3b,0x39,0x48,0x36,0x40,0x4c,0x2f,0x3c,
    0xd,0x50,0x5c,0x28,0x42,0x5f,0x47,0x4e,0x27,
};

int getC(int128 n){
    int x=((n%94)*(n%109)%117+n%113)/2;
    for(int i=0;i<25;i++){
        if(x==h[i]) return f[i];
    }
    return 1;
}

vector<int128>v;
void factor(int128 n){
    if(miller_rabin(n)){
        v.push_back(n);
        return;
    }
    int128 d=n;
    srand(unsigned(time(NULL)));
    int c=getC(n);
    while(d==n){
        d=pollard_rho(n,c);
        c=rand()%(n-1)+1;
    }
    factor(d);
    factor(n/d);
}

int main(){
    int128 x=read();
    factor(x);
    sort(v.begin(),v.end());
    for(auto x:v){
        write(x);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}