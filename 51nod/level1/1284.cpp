#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll N;
    cin>>N;
    ll ans=N-N/2-N/3-N/5-N/7+N/6+N/10+N/15+N/14+N/21+N/35-N/105-N/70-N/42-N/30+N/210;
    cout<<ans<<endl;
    return 0;
}