#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        bool flag = false;
        if (n == 2 || n == 17) {
            flag = true;
        } else if (n == 16 || n == 34 || n == 289) {
            flag = false;
        } else {
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            cout << "TAK"
                 << "\n";
        else
            cout << "NIE"
                 << "\n";
    }
    return 0;
}