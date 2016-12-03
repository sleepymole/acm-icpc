#include<iostream>
using namespace std;
const int maxn=100010;
int prime[maxn],cnt;
bool sgn[maxn];

void get_prime(){
    sgn[1]=true;
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
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x<maxn){
            if(!sgn[x])cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            bool flag=true;
            for(int j=0;j<cnt;j++){
                if(x%prime[j]==0){
                    flag=false;
                    break;
                }
            }
            if(flag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}