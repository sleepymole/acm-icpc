#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int P=int(1e9+7);
const int N=100000;
int a[N],p1[30],q1[30],p2[30],q2[30];


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        vector<pair<int,int>>v;
        for(int j=0;j<30;j++){
            p1[j]=p2[j]=i;
            if(q1[j]<i) q1[j]=i;
            if(q2[j]<i) q2[j]=i;
            while(q1[j]<n&&!(a[q1[j]]&(1<<j))) q1[j]++;
            while((q2[j]<n&&a[q2[j]]&(1<<j))) q2[j]++;
            v.push_back(make_pair(q1[j],j));
            v.push_back(make_pair(q2[j],j+30));
        }
        sort(v.begin(),v.end());
        int x=a[i],y=a[i],s=i;
        auto it=v.begin();
        while(true){
            int val=(ll)x*y%P;
            int e=it->first;
            ans=(ans+(ll)(e-s)*val)%P;
            while(it!=v.end()&&(it->first)==e){
                int bt=it->second;
                if(bt<30) x=x|(1<<bt);
                else y=(y|(1<<(bt-30)))^(1<<(bt-30));
                it++;
            }
            if(it==v.end()){
                ans=(ans+(ll)(n-e)*x%P*y)%P;
                break;
            }
            s=e;
        }
    }
    printf("%d\n",ans);
    return 0;
}