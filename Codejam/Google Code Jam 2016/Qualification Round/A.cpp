#include<iostream>
#include<cstring>
using namespace std;
int digit[10],cnt;

bool check(int n){
    while(n){
        if(!digit[n%10]){
            digit[n%10]++;
            cnt++;
        }
        n/=10;
    }
    return cnt==10;
}

int main(){
    int T;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        memset(digit,0,sizeof(digit));
        cnt=0;
        int n;
        cin>>n;
        cout<<"Case #"<<ca<<": ";
        if(n==0){
            cout<<"INSOMNIA"<<endl;
            continue;
        }
        int ans;
        for(int i=1;i<=1000;i++){
            if(check(i*n)){
                ans=i*n;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}