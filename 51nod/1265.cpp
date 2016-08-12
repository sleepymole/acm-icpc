#include<iostream>
using namespace std;

struct Point{
    int x,y,z;
};

bool check(Point p1,Point p2,Point p3,Point p4){
    p1.x-=p4.x;p1.y-=p4.y;p1.z-=p4.z;
    p2.x-=p4.x;p2.y-=p4.y;p2.z-=p4.z;
    p3.x-=p4.x;p3.y-=p4.y;p3.z-=p4.z;
    int a=p1.y*p2.z-p1.z*p2.y;
    int b=p1.z*p2.x-p1.x*p2.z;
    int c=p1.x*p2.y-p1.y*p2.x;
    if(p3.x*a+p3.y*b+p3.z*c==0) return true;
    return false;
}

int main(){
    Point p1,p2,p3,p4;
    int t;
    cin>>t;
    while(t--){
        cin>>p1.x>>p1.y>>p1.z;
        cin>>p2.x>>p2.y>>p2.z;
        cin>>p3.x>>p3.y>>p3.z;
        cin>>p4.x>>p4.y>>p4.z;
        if(check(p1,p2,p3,p4)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}