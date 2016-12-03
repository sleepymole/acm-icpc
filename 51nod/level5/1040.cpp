#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=100010;

int euler_phi(int n){
    int ans=n;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

int euler[maxn];
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

ll cal(int d,int n){
    if(n/d<maxn) return (ll)euler[n/d]*d;
    else return (ll)euler_phi(n/d)*d;
}
int main(){
    getEuler();
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n/i;i++){
        if(n%i==0){
            sum+=cal(i,n);
            if(i!=n/i){
                sum+=cal(n/i,n);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}