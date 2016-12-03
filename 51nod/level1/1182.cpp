#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100010;
char str[maxn];
int a[26];

int main(){
    scanf("%s",str);
    int n=strlen(str);
    for(int i=0;i<n;i++){
        if(str[i]>='a'&&str[i]<='z'){
            a[str[i]-'a']++;
        }else{
            a[str[i]-'A']++;
        }
    }
    sort(a,a+26);
    int sum=0;
    for(int i=1;i<=26;i++){
        sum+=a[i-1]*i;
    }
    cout<<sum<<endl;
    return 0;
}