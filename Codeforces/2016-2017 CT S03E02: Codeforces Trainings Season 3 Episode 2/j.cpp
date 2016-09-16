#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    ll odd=N/2+N%2,even=N-odd;
    ll ans=even*(even-1)*(even-2)/6;
    ans+=odd*(odd-1)/2*even;
    cout<<ans<<endl;
    return 0;
}