#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1000010;

void pre_kmp(char x[],int m,int fail[]){
    int i=0,j=fail[0]=-1;
    while(i<m){
        while(-1!=j&&x[i]!=x[j]) j=fail[j];
        if(x[++i]==x[++j]) fail[i]=fail[j];
        else fail[i]=j;
    }
}

int kmp(char x[],int m,char s[],int n){
    static int fail[maxn];
    pre_kmp(x,m,fail);
    int i=0,j=0;
    while(i<n){
        while(-1!=j&&s[i]!=x[j]) j=fail[j];
        i++;j++;
        if(j==m) return i-m+1;
    }
    return -1;
}

int main(){

    return 0;
}