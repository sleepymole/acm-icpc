#include <iostream>
using namespace std;

int main() {
    int w, m;
    cin >> w >> m;
    bool flag = true;
    while (m) {
        if (m % w == 0)
            m /= w;
        else if (m % w == 1)
            m = (m - 1) / w;
        else if (m % w == w - 1)
            m = (m + 1) / w;
        else {
            flag = false;
            break;
        }
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}