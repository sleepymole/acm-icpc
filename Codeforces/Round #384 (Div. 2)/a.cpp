#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=100010;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    string str;
    cin>>str;
    a--;b--;
    if(str[a]==str[b]) puts("0");
    else puts("1");
    return 0;
}