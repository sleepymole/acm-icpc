#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=10010;
struct Number{
    string str;
    bool operator<(const Number& rhs)const{
        string tmp1=str+rhs.str;
        string tmp2=rhs.str+str;
        return tmp1<tmp2;
    }
}a[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].str;
    }
    sort(a,a+n);
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].str.length();j++){
            putchar(a[i].str[j]);k++;
            if(k%1000==0) putchar('\n');
        }
    }
    return 0;
}