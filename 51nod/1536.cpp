#include <iostream>
using namespace std;
const int N = 1000;
bool notprime[N + 1];

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            int x = i;
            while (x <= n) {
                ans++;
                x *= i;
            }
            for (int j = i + i; j <= n; j += i) {
                notprime[j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
