#include<iostream>
using namespace std;
const int maxn=25010;
int a[2000];

int main(){
    int n;
    cin>>n;
    if(n>=1024){
        for(int i=0;i<n;i++){
            cout<<0;
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i]=-1;
    }
    int p=2,c=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=0) continue;
        for(int j=i;j<=n;j+=p){
            a[j]=c;
        }
        c++;p<<=1;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}