#include<iostream>
using namespace std;
const int maxn=600010;
int a[maxn],b[maxn];

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>b[i];
        a[b[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        for(int j=i+i;j<=n;j+=i){
            if(a[j]){
                for(int x=1;x<=k;x++){
                    if(b[x]==i){
                        cout<<x<<" ";
                        break;
                    }
                }
                for(int x=1;x<=k;x++){
                    if(b[x]==j){
                        cout<<x<<endl;
                        break;
                    }
                }
                return 0;
            }
        }
    }
    cout<<"0 0"<<endl;
    return 0;
}