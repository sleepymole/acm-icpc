#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string str[1010];
int main(){
    bool flag=false;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str[i];
        if(!flag){
            if(str[i][0]=='O'&&str[i][1]=='O'){
                str[i][0]=str[i][1]='+';
                flag=true;
            }else if(str[i][3]=='O'&&str[i][4]=='O'){
                str[i][3]=str[i][4]='+';
                flag=true;
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<str[i]<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}