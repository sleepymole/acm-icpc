#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char str[100010];
int a[26],tot;
int main(){
    scanf("%s",str);
    int n=strlen(str);
    int ans=n+1,p=0,q=0;
    a[str[0]-'A']++;tot++;
    while(true){
        if(tot<26||p==q){
            if(q+1==n) break;
            q++;
            a[str[q]-'A']++;
            if(a[str[q]-'A']==1) tot++;
        }else{
            ans=min(ans,q-p+1);
            a[str[p]-'A']--;
            if(a[str[p]-'A']==0) tot--;
            p++;
        }
    }
    if(ans<=n) cout<<ans<<endl;
    else cout<<"No Solution"<<endl;
    return 0;
}