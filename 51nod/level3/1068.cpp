#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int sum=0,n=str.length();
        for(int i=0;i<n;i++){
            sum=(sum+str[i]-'0')%3;
        }
        if(sum) cout<<'A'<<endl;
        else cout<<'B'<<endl;
    }
    return 0;
}