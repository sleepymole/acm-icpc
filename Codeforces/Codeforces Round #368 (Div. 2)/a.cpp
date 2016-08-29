#include<iostream>
#include<string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string str;
    bool flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>str;
            if(str=="M"||str=="C"||str=="Y"){
                flag=false;
            }
        }
    }
    if(flag) cout<<"#Black&White"<<endl;
    else cout<<"#Color"<<endl;
    return 0;
}