#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int main(){
    int n;
    cin>>n;
    int R,O;
    int Min=INF,Sum=0;
    for(int i=0;i<n;i++){
        cin>>R>>O;
        Sum+=O;
        Min=min(Min,R-O);
    }
    cout<<Sum+Min<<endl;
    return 0;
}