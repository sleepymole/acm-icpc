#include<iostream>
using namespace std;
const int maxn=50010;
int a[maxn],sum[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[0]=0;
    for(int i=2;i<n;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]; 
    }
    sum[n]=sum[n-1];
    if(sum[n]==0){
        cout<<0<<endl;
        return 0;
    }
    int x=-1;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            bool flag=true;
            for(int j=i;j<=n;j+=i){
                if(sum[j]-sum[j-i]==0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                x=n/i;
                break;
            }
        }
    }
    cout<<x<<endl;
    return 0;
}