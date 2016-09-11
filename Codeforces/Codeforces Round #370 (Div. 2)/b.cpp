#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    string str;
    cin>>str;
    int L=0,R=0,U=0,D=0;
    int n=str.length();
    if(n%2==1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(str[i]=='U') U++;
        else if(str[i]=='R') R++;
        else if(str[i]=='D') D++;
        else if(str[i]=='L') L++;
    }
    if(L>R) swap(L,R);
    if(D>U) swap(D,U);
    int ans=(R-L)/2+(U-D)/2+(R-L)%2;
    cout<<ans<<endl;
    return 0;
}