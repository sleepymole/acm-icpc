#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Date{
    int s,e,x;
    Date(int _s=0,int _e=0,int _x=0):s(_s),e(_e),x(_x){}
    bool operator<(const Date& rhs)const{
        return s<rhs.s;
    }    
};
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

inline void write(int x){
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}

int main(){
    int n=read();
    int y0,m0,d0,y1,m1,d1,s,e,x;
    vector<Date>dates;
    for(int i=0;i<n;i++){
        y0=read();m0=read();d0=read();y1=read();m1=read();d1=read();x=read();
        if((y1-y0==1)&&(m0==12)&&(m1==1)&&(d0>d1)) continue;
        if(y0<y1||(y0==y1&&m1-m0>1)||(y0==y1&&(m1-m0==1)&&(d0<=d1))){
            s=y0*500+m0*40+d0;
            e=y1*500+m1*40+d1;
            dates.push_back(Date(s,e,x));
        }
    }
    sort(dates.begin(),dates.end());
    int q=read(),y,m,d;
    priority_queue<int,vector<int>,greater<int> >Q;
    while(q--){
        y=read();m=read();d=read();
        int v=y*500+m*40+d,sz=dates.size();
        for(int i=0;i<sz;i++){
            if(v<dates[i].s) break;
            if(v>=dates[i].s&&v<=dates[i].e){
                Q.push(dates[i].x);
            }
        }
        write(Q.size());
        putchar(' ');
        while(!Q.empty()){
            write(Q.top());
            putchar(' ');
            Q.pop();
        }
        putchar('\n');
    }
    return 0;
}