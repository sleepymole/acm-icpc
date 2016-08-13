#include<iostream>
using namespace std;
const int maxn=100010;
int a[maxn];
int main(){
    a[0]=0;
    a[1]=1;
    for(int i=2;i<maxn;i++){
        a[i]=a[i/2]+(i%2)*a[i/2+1];
    }
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int maxNum=0;
        for(int i=0;i<=n;i++){
            maxNum=a[i]>maxNum?a[i]:maxNum;
        }
        cout<<maxNum<<endl;
    }
    return 0;
}