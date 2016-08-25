#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[100010];
int main(){
    scanf("%s",str);
    int n=strlen(str);
    int p=n,q=n;
    for(int i=0;i<n;i++){
        if(str[i]>'a'){
            p=i;break;
        }
    }
    if(p==n){
        for(int i=0;i<n-1;i++){
            putchar('a');
        }
        putchar('z');
        putchar('\n');
        return 0;
    }
    for(int i=p+1;i<n;i++){
        if(str[i]=='a'){
            q=i;break;
        }
    }
    for(int i=0;i<n;i++){
        if(i<p||i>=q) putchar(str[i]);
        else{
            if(str[i]=='a') putchar('z');
            else putchar(str[i]-1);
        }
    }
    putchar('\n');
    return 0;
}