#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,d,n;
        cin>>a>>b>>d>>n;
        int ans=0;
        int k=a*b;
        if(k<10){
            ans=d==a*b?n:0;
        }else if(k/10+k%10<10){
            ans+=(d==(k/10+k%10))?n-1:0;
            ans+=(d==k/10)?1:0;
            ans+=(d==k%10)?1:0;
        }else{
            ans=(n==1&&d==k/10)?1:0;
            ans+=(n>1&&d==k/10+1)?1:0;
            ans+=(d==k%10)?1:0;
            int r=(k/10+k%10)%10;
            ans+=(d==r&&n>1)?1:0;
            ans+=(d==(r+1)&&n>2)?(n-2):0;
        }
        cout<<ans<<endl;
    }
    return 0;
}