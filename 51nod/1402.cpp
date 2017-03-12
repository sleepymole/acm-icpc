#include <iostream>
using namespace std;
int x[55], t[55], dp[51];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> x[i] >> t[i];
        }
        x[0] = 1;
        t[0] = 0;
        x[m + 1] = n;
        t[m + 1] = n - 1;
        for (int i = 1; i <= m; i++) {
            if (t[i] > t[i - 1]) t[i] = min(t[i], t[i - 1] + x[i] - x[i - 1]);
            if (t[i] > t[i + 1]) t[i] = min(t[i], t[i + 1] + x[i + 1] - x[i]);
        }
        t[m + 1] = t[m] + x[m + 1] - x[m];
        for (int i = m; i >= 1; i--) {
            if (t[i] > t[i - 1]) t[i] = min(t[i], t[i - 1] + x[i] - x[i - 1]);
            if (t[i] > t[i + 1]) t[i] = min(t[i], t[i + 1] + x[i + 1] - x[i]);
        }
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            int s = t[i + 1] - t[i];
            if (s < 0) s *= -1;
            ans = max(ans, max(t[i], t[i + 1]) + (x[i + 1] - x[i] - s) / 2);
        }
        cout << ans << endl;
    }
    return 0;
}