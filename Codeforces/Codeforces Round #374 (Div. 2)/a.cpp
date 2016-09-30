#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<int>v;
    bool on=false;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(on){
            if(str[i]=='W'){
                on=false;
                v.push_back(cnt);
            }else{
                cnt++;
            }
        }else{
            if(str[i]=='B'){
                cnt=1;
                on=true;
            }
        }
    }
    if(on) v.push_back(cnt);
    cout<<v.size()<<endl;
    for(int i=0;i<(int)v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}