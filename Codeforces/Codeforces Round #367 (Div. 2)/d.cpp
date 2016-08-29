#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=10000000;
int nextNode[maxn][2],val[maxn],cnt[maxn];
struct Trie{
    int root,tot;
    int newNode(){
        memset(nextNode[tot],-1,sizeof(nextNode[tot]));
        return tot++;
    }
    void initial(){
        tot=0;
        root=newNode();
    }
    void insert(int x){
        int p=root;
        for(int i=31;i>=0;i--){
            int idx=((1<<i)&x)?1:0;
            if(nextNode[p][idx]==-1) nextNode[p][idx]=newNode();
            p=nextNode[p][idx];
        }
        val[p]=x;
        cnt[p]++;
    }
    void erase(int x){
        int p=root,pre,tmp;
        for(int i=31;i>=0;i--){
            int idx=((1<<i)&x)?1:0;
            if(nextNode[p][idx^1]!=-1){
                pre=p;tmp=idx;
            }
            p=nextNode[p][idx];
        }
        cnt[p]--;
        if(cnt[p]==0){
            nextNode[pre][tmp]=-1;
        }
    }
    int search(int x){
        int p=root;
        for(int i=31;i>=0;i--){
            int idx=((1<<i)&x)?1:0;
            if(idx==0) p=nextNode[p][1]!=-1?nextNode[p][1]:nextNode[p][0];
            else p=nextNode[p][0]!=-1?nextNode[p][0]:nextNode[p][1];
        }
        return x^val[p];
    }
}tr;
int main(){
    tr.initial();
    tr.insert(0);
    int q;
    cin>>q;
    while(q--){
        char ch=getchar();
        while(ch!='+'&&ch!='-'&&ch!='?') ch=getchar();
        int x;
        cin>>x;
        if(ch=='+') tr.insert(x);
        else if(ch=='-') tr.erase(x);
        else cout<<tr.search(x)<<endl;
    }
    return 0;
}