#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[101];
int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int n,k;
    cin>>n>>k;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        a[str.length()]++;
    }
    cin>>str;
    int x=str.length();
    int sum=0;
    for(int i=1;i<x;i++){
        sum+=a[i];
    }
    int best=sum+1+sum/k*5;
    sum+=a[x]-1;
    int bad=sum+1+sum/k*5;
    cout<<best<<" "<<bad<<endl;
    return 0;
}