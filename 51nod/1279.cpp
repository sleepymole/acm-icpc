#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50010;
int w[maxn], d[maxn], a[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < m; i++) cin >> d[i];
    a[0] = w[0];
    for (int i = 1; i < n; i++) a[i] = min(a[i - 1], w[i]);
    int k = n - 1, ans = 0;
    for (int i = 0; i < m; i++) {
        if (d[i] <= a[k]) {
            ans++;
            k--;
        } else {
            while (k >= 0 && d[i] > a[k]) k--;
            if (k >= 0) {
                ans++;
                k--;
            }
        }
        if (k < 0) break;
    }
    cout << ans << endl;
    return 0;
}