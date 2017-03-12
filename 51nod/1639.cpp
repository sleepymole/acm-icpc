#include <iostream>
using namespace std;
double dp[1010];
int main() {
    int n;
    cin >> n;
    dp[1] = 1.0;
    for (int k = 1; k < n; k++) {
        dp[k + 1] = dp[k] * 2.0 * (n - k) / (2.0 * (n - k) + 1);
    }
    cout << dp[n] << endl;
    return 0;
}