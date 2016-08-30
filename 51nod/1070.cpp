#include<iostream>
#include<map>
using namespace std;

int main(){
    int a = 0, b = 1, c;
    map<int, int> mp;
    while(b<(1e9)){
        c = a + b;
        mp[c] = 1;
        a = b;
        b = c;
    }
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(mp[n])
            cout << 'B' << endl;
        else
            cout << 'A' << endl;
    }
    return 0;
}