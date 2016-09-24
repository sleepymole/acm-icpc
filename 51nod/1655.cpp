#include<iostream>
using namespace std;
int a[101][101];

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<n<<endl;
        if(n%2==0){
            cout<<"No solution"<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            int s=2*i-1;
            for(int j=i+1;j<=n;j++){
                s=s%n;
                if(s==0) s=n;
                a[i][j]=s;
                s++;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                cout<<i<<" "<<j<<" "<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}