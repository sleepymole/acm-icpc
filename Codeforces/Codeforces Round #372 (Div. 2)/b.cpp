#include<iostream>
#include<string>
#include<set>
#include<cstdio>
using namespace std;

int main(){
    // freopen("input","r",stdin);
    // freopen("output","w",stdout);
    string str;
    cin>>str;
    int n=str.length();
    if(n<26){
        cout<<-1<<endl;
        return 0;
    }
    bool found=false;
    for(int i=0;i<n;i++){
        if(i+26>n) break;
        set<char>s;
        int cnt=0;
        for(int j=0;j<26;j++){
            if(str[i+j]=='?') cnt++;
            else{
                s.insert(str[i+j]);
            }
        }
        if(s.size()+cnt==26){
            found=true;
            set<char>tmp;
            for(int k=0;k<26;k++){
                if(s.count(k+'A')==0){
                    tmp.insert(k+'A');
                }
            }
            for(int j=0;j<26;j++){
                if(str[i+j]=='?'){
                    char ch=*(tmp.begin());
                    str[i+j]=ch;
                    tmp.erase(ch);
                }
            }
            break;
        }
    }
    if(!found){
        cout<<-1<<endl;
    }else{
        for(int i=0;i<n;i++){
            if(str[i]=='?') putchar('Z');
            else putchar(str[i]);
        }
        putchar('\n');
    }
    return 0;
}