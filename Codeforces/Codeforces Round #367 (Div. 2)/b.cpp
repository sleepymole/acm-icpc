#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int x[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    int q,m;
    cin>>q;
    while(q--){
        cin>>m;
        int pos=upper_bound(x,x+n,m)-x;
        cout<<pos<<endl;
    }
    return 0;
}