#include<iostream>
using namespace std;

int main(){
    int n,x,a=0,b=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==5) a++;
        else b++;
    }
    if(b==0) cout<<-1<<endl;
    else{
        if(a<9) cout<<0<<endl;
        else{
            for(int i=0;i<9*(a/9);i++) cout<<5;
            for(int i=0;i<b;i++) cout<<0;
            cout<<endl;
        }
        
    }
    return 0;
}