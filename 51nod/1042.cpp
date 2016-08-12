#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;

ll work1(int n){
    if(n==1) return 10;
    return 9*(ll)pow(10,n-1)*n+work1(n-1);
}
ll solve1(ll num){
    if(num<10) return num+1;
    char str[20];
    sprintf(str,"%lld",num);
    int n=strlen(str);
    ll ans=work1(n-1);
    int lead=str[0]-'0';
    for(int i=1;i<lead;i++){
        ans+=(ll)pow(10,n-1)*n;
    }
    ll r=num%(ll)pow(10,n-1);
    ans+=(r+1)*n;
    return ans;
}
ll work(int n){
    if(n==1) return 1;
    if(n==0) return 0;
    return 10*work(n-1)+(ll)pow(10,n-1);
}
ll solve(ll num,int key){
    if(num==0) return 0;
    if(num<10) return key<=num;
    char str[20];
    sprintf(str,"%lld",num);
    int n=strlen(str);
    ll ans=0;
    ans+=work(n-1);
    int lead=str[0]-'0';
    for(int i=1;i<lead;i++){
        if(i==key) ans+=work(n-1)+pow(10,n-1);
        else ans+=work(n-1);
    }
    ll r=num%(ll)pow(10,n-1);
    ans+=solve(r,key);
    if(lead==key) ans+=r+1;
    return ans;
}
int main(){
    ll num[10],a,b;
    cin>>a>>b;
    for(int i=1;i<=10;i++){
        num[i]=solve(b,i)-solve(a-1,i);
    }
    num[0]=solve1(b)-solve1(a-1);
    for(int i=1;i<=9;i++){
        num[0]-=num[i];
    }
    for(int i=0;i<=9;i++){
        cout<<num[i]<<endl;
    }
    return 0;
}