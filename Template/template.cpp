#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

void write(int n){
    if(n>=10)write(n/10);
    putchar(n%10+'0');
}

int main(){
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int startTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    
    int endTime=(int)((double)clock()/CLOCKS_PER_SEC*1000);
    cout<<(endTime-startTime)<<"ms"<<endl;
    return 0;
}
