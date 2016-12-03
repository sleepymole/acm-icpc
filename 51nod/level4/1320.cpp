#include<iostream>
using namespace std;
int d[50];

bool check(int l,int r){
    for(int i=1;i<=128;i++){
        bool flag=true;
        for(int j=l;j<=r;j++){
            if(d[j]!=__builtin_ctz(i+j)){
                flag=false;
                break;
            }
        }
        if(flag) return true;
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>d[i];
            if(d[i]>6) d[i]=6;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans+=check(i,j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}