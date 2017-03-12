#include <iostream>
using namespace std;
typedef long long ll;
const int P = 1000000009;
int a = 691504013, b = 308495997;

int power_mod(int a, ll n) {
    n %= (P - 1);
    int r = 1;
    while (n) {
        if (n & 1) r = (ll) r * a % P;
        a = (ll) a * a % P;
        n >>= 1;
    }
    return r;
}

int inverse(int a, int m) {
    return a == 1 ? 1 : (ll) inverse(m % a, m) * (m - m / a) % m;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        int q = power_mod(a, k), ans, r = 1;
        if (q == 1)
            ans = (n + 1) % P;
        else
            ans = (ll)(power_mod(q, n + 1) - 1) * inverse(q - 1, P) % P;
        for (int i = 1; i <= k; i++) {
            r = (ll) r * (k - i + 1) % P * inverse(i, P) % P * (P - 1) % P;
            q = (ll) power_mod(a, k - i) * power_mod(b, i) % P;
            if (q == 1)
                ans = (ans + (n + 1) % P * r) % P;
            else
                ans = (ans +
                       (ll) r * (power_mod(q, n + 1) - 1) % P *
                           inverse(q - 1, P)) %
                      P;
        }
        ans = (ll) ans * power_mod(276601605, k) % P;
        cout << ans << endl;
    }
    return 0;
}