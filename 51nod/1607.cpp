#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
typedef long long ll;
const ll mod=1000000007;
ll F[25],f[25],p[25];

ll kpow(ll a,int n){
    ll r=1;
    while(n){
        if(n%2)r*=a;
        a=a*a;
        n/=2;
    }
    return r;
}
void initial(){
    F[1]=f[1]=285;
    F[2]=f[2]=4050;
    p[0]=1;
    for(int i=1;i<25;i++){
        p[i]=10*p[i-1]%mod;
    }
    for(int i=3;i<25;i++){
        f[i]=(100*f[i-2]+p[i-2]*f[2]%mod)%mod;
        F[i]=((f[i]-10*f[i-2])%mod+mod)%mod;
    }
}
ll work1(ll num,int n){ 
    if(n==0) return 0;
    if(n==1){
        ll t=0;
        for(int i=1;i<=num;i++) t+=i*i;
        return t;
    }
    ll lead=num/((ll)kpow(10,n-1));
    ll ans=0;
    for(int i=0;i<lead;i++){
        ans=(ans+10*f[n-2]+90*p[n-2]*i)%mod;
    } 
    ll mid=num%((ll)kpow(10,n-1))/10;
    ll last=num%10;
    ans=ans+(mid+1)%mod*lead*last*(last+1)+(last+1)*work1(mid,n-2)%mod;
    ans=ans+mid%mod*lead*(last+1+9)*(9-last)+(9-last)*work1(mid-1,n-2);
    return ans%mod;
}
ll work2(ll num){
    if(num<10){
        ll t=0;
        for(int i=1;i<=num;i++) t+=i*i;
        return t;
    }
    char str[25];
    sprintf(str,"%lld",num);
    int n=strlen(str);

    ll ans=0;
    for(int i=1;i<n;i++){
        ans=(ans+F[i])%mod;
    }
    ll lead=str[0]-'0';
    for(int i=1;i<lead;i++){
        ans=(ans+90*i*p[n-2]%mod+10*f[n-2])%mod;
    }
    ll mid=num%((ll)kpow(10,n-1))/10;
    ll last=str[n-1]-'0';
    ans=ans+(mid+1)%mod*lead*last*(last+1)+(last+1)*work1(mid,n-2)%mod;
    ans=ans+mid%mod*lead*(last+1+9)*(9-last)+(9-last)*work1(mid-1,n-2);
    return ans;
}


int main(){
    initial();
    ll L,R;
    cin>>L>>R;
    ll ans=work2(R)-work2(L-1);
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
    return 0;
}