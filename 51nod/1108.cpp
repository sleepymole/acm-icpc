#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 10000;
ll x[maxn], y[maxn], z[maxn];

ll work(ll *a, int n) {
    sort(a, a + n);
    ll ans = 0, mid = a[n / 2];
    for (int i = 0; i < n; i++) {
        if (mid > a[i])
            ans += mid - a[i];
        else
            ans += a[i] - mid;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = work(x, n) + work(y, n) + work(z, n);
    cout << ans << endl;
    return 0;
}