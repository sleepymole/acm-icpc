#include <iostream>
using namespace std;
typedef long long ll;
ll sum[501][501];

int main() {
    int x, m, n;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            sum[i][j] = sum[i - 1][j] + x;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            ll maxsum = 0;
            for (int k = 1; k <= n; k++) {
                maxsum += sum[j][k] - sum[i - 1][k];
                if (maxsum < 0) maxsum = 0;
                ans = max(ans, maxsum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}