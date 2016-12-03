#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200010;;
int a[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int mod=0;
    for(int i=0;i<n-1;i++){
        for(int j=a[i]+a[i];j<=a[n-1]+a[i];j+=a[i]){
            int pos=lower_bound(a+i+1,a+n,j)-a-1;
            if(pos>i) mod=max(mod,a[pos]%a[i]);
        }
    }
    cout<<mod<<endl;
    return 0;
}