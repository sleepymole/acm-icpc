#include <iostream>
using namespace std;
int cs[1001];
int main() {
    for (int i = 1; i <= 1000; i++) {
        int x = i;
        while (x % 2 == 0) x /= 2;
        while (x % 5 == 0) x /= 5;
        if (x == 1)
            cs[i] = 0;
        else {
            int r = 1, m;
            for (m = 1;; m++) {
                r = r * 10 % x;
                if (r == 1) break;
            }
            cs[i] = m;
        }
    }
    int n;
    cin >> n;
    int maxNum = -1, ans = -1;
    for (int i = 1; i <= n; i++) {
        if (cs[i] > maxNum) {
            maxNum = cs[i];
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}