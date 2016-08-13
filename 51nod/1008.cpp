#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    int N,P;
    cin>>N>>P;
    int ans=1;
    for(int i=1;i<=N;i++){
        ans=(ll)ans*i%P;
    }
    cout<<ans<<endl;
    return 0;
}