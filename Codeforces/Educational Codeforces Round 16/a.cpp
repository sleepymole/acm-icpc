#include<iostream>
#include<string>
using namespace std;

bool check(int x,int y){
    return x>0&&x<=8&&y>0&&y<=8;
}
int main(){
    string str;
    cin>>str;
    int x=str[0]-'a'+1;
    int y=str[1]-'0';
    int ans=0;
    if(check(x,y+1)) ans++;
    if(check(x,y-1)) ans++;
    if(check(x+1,y)) ans++;
    if(check(x-1,y)) ans++;
    if(check(x+1,y+1)) ans++;
    if(check(x-1,y-1)) ans++;
    if(check(x+1,y-1)) ans++;
    if(check(x-1,y+1)) ans++;
    cout<<ans<<endl;
    return 0;
}