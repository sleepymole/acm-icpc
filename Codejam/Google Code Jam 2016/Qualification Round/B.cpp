#include<iostream>
#include<string>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        string str;
        cin>>str;
        int n=str.length();
        int l=0,r=n-1,ans=0;
        if(str[l]=='-'){
            ans++;
            while(l<n&&str[l]=='-') l++;
        }
        if(r>l&&str[r]=='-'){
            ans+=2;
            while(str[r]=='-') r--;
        }
        int cnt=0;
        if(l<r){
            for(int i=l;i<r;i++){
                if(str[i]=='-'&&str[i+1]=='+') cnt++;
            }
        }
        ans+=2*cnt;
        cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}