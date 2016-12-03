#include<iostream>
using namespace std;
const int maxn=1000010;
int prime[maxn],cnt;
bool notprime[maxn];

void getPrime(){
    for(int i=2;i<maxn;i++){
        if(!notprime[i]){
            prime[cnt++]=i;
            for(int j=i+i;j<maxn;j+=i){
                notprime[j]=true;
            }
        }
    }
}

int main(){
    getPrime();
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int M=N+1;
        for(int i=0;i<cnt;i++){
            if(prime[i]>N) break;
            int base=prime[i];
            while(base<=N/prime[i]){
                base*=prime[i];
            }
            M=max(M,(N/base+1)*base);
        }
        cout<<M<<endl;
    }
    return 0;
}