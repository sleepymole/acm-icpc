#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10010;
ll a[maxn], sum1[maxn], sum2[maxn];
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++) {
        sum1[i] = sum1[i - 1] + a[i];
        sum2[i] = sum2[i - 1] + a[i] * a[i];
    }
    ll ans = INF;
    for (int i = 0; i + n <= m; i++) {
        ll s = (sum2[i + n] - sum2[i]) -
               1.0 * (sum1[i + n] - sum1[i]) * (sum1[i + n] - sum1[i]) / n;
        ans = min(ans, s);
    }
    cout << ans << endl;
    return 0;
}