#include <iostream>
using namespace std;
const int mod = 1000000007;
int dp[100010],
    arr[13] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < 13; i++) {
        for (int j = arr[i]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}