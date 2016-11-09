#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int S,W,A;
        double p1,p2;
        cin>>S>>W>>A>>p1>>p2;
        double k1=p1/(1-p1),k2=p2/(1-p2);
        double s=(pow(k1,W+A)-1)/(k1-1)
            +pow(k1,W+A-1)*k2*(pow(k2,S-A)-1)/(k2-1);
        double ans=1-(pow(k1,W)-1)/(k1-1)/s;
        printf("%.10lf\n",ans);
    }
    return 0;
}