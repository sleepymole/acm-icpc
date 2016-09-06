#include<iostream>
#include<map>
using namespace std;
const int maxn=2001;
int x[maxn],y[maxn];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        map<pair<int,int>,int>mp;
        for(int j=i+1;j<n;j++){
            int p=x[j]-x[i];
            int q=y[j]-y[i];
            int g=gcd(p,q);
            p/=g; q/=g;
            if(p<0) p*=-1,q*=-1;
            mp[make_pair(p,q)]++;
        }
        auto it=mp.begin();
        while(it!=mp.end()){
            int m=(*it).second;
            ans+=m*(m-1)/2;
            it++;
        }
    }
    cout<<((long long)n*(n-1)*(n-2)/6-ans)<<endl;
    return 0;
}