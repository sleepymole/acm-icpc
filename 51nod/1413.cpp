#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] - '0' > ans) ans = str[i] - '0';
    }
    cout << ans << endl;
    return 0;
}