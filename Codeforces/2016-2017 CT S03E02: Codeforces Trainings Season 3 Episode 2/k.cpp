#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    int k;
    cin>>k;
    while(k--){
        int n,m;
        cin>>n>>m;
        
        if(n%2!=0&&n%3!=0) swap(m,n);
        //cout<<n<<" "<<m<<endl;
        if((ll)m*n%6!=0){
            cout<<"No"<<endl;
        }else if((m<3&&n<3)||m==1||n==1){
            cout<<"No"<<endl;
        }else if(n%2==0){
            if(m%3==0){
                cout<<"Yes"<<endl;
            }else{
                if(n%3==0) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }else{
            if(m%2==0){
                cout<<"Yes"<<endl;
            }else{
                if(n%2==0) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
    return 0;
}