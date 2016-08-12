#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=50010;
int a[maxn];
int main(){
    int N;
    cin>>N;
    ll totSum=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        totSum+=a[i];
    }
    ll maxSum=0,sum=0;
    for(int i=0;i<N;i++){
        if(sum+a[i]<=0) sum=0;
        else sum+=a[i];
        maxSum=max(maxSum,sum);
    }
    sum=0;
    ll minSum=0;
    for(int i=0;i<N;i++){
        if(sum+a[i]>=0) sum=0;
        else sum+=a[i];
        minSum=min(minSum,sum);
    }
    maxSum=max(maxSum,totSum-minSum);
    cout<<maxSum<<endl;
    return 0;
}