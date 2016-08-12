#include<iostream>
using namespace std;
const int maxn=100010;
int prime[maxn],cnt;
bool sgn[maxn];

void get_prime(){
    for(int i=2;i<maxn;i++){
        if(!sgn[i]){
            prime[cnt++]=i;
            for(int j=i+i;j<maxn;j+=i){
                sgn[j]=true;
            }
        }
    }
}
int main(){
    get_prime();
    int n;
    cin>>n;
    int flag=1;
    int tot=0;
    for(int i=0;i<cnt;i++){
        if(n%prime[i]==0){
            n/=prime[i];
            if(n%prime[i]==0){
                flag=0;
                break;
            }
            tot++;
        }
        if(n==1) break;
    }
    if(n>1) tot++;
    if(flag==0) cout<<0<<endl;
    else if(tot%2) cout<<-1<<endl;
    else cout<<1<<endl;
    return 0;
}