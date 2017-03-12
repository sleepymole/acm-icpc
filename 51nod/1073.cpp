#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = (ans + k) % i;
        ans = ans == 0 ? i : ans;
    }
    cout << ans << endl;
    return 0;
}