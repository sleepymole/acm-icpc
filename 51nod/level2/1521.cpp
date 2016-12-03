#include<iostream>
#include<set>
using namespace std;

int main(){
    int n,k,a,m,x;
    cin>>n>>k>>a>>m;
    set<pair<int,int> >st;
    st.insert(make_pair(n+1,0));
    int cnt=(n+1)/(a+1);
    for(int i=1;i<=m;i++){
        cin>>x;
        auto it=st.lower_bound(make_pair(x,0));
        int l=it->second;
        int r=it->first;
        if(it==st.end()||x<=l||r<=x){
            cout<<i<<endl;
            return 0;
        }
        st.erase(it);
        cnt=cnt-(r-l)/(a+1)+(x-l)/(a+1)+(r-x)/(a+1);
        if(cnt<k){
            cout<<i<<endl;
            return 0;
        }
        st.insert(make_pair(x,l));
        st.insert(make_pair(r,x));
    }
    cout<<-1<<endl;
    return 0;
}