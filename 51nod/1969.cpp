#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int P = 998244353;
const int mod = 1000000007;

int power_mod(int a, int n) {
    int ret = 1;
    while (n) {
        if (n & 1) ret = (ll) ret * a % mod;
        a = (ll) a * a % mod;
        n >>= 1;
    }
    return ret;
}

int inverse(int a, int m) {
    return a == 1 ? 1 : (ll) inverse(m % a, m) * (m - m / a) % m;
}

int main() {
    int T, base;
    scanf("%d%d", &T, &base);
    int r = power_mod(base, T);
    int inv = base == 0 ? 0 : inverse(base, mod);
    int ans = 0;
    for (int i = 1; i <= T; i++) {
        int n;
        scanf("%d", &n);
        int d = sqrt(24.0 * n + 1);
        while ((ll) d * d < 24LL * n + 1) d++;
        r = (ll) r * inv % mod;
        if ((ll) d * d - 24LL * n - 1 == 0) {
            if ((d + 1) % 6 == 0) {
                int id = (d + 1) / 6;
                if (id % 2 == 0)
                    ans = (ans + r) % mod;
                else
                    ans = (ans + (ll)(P - 1) * r) % mod;
            } else if ((1 - d) % 6 == 0) {
                int id = (1 - d) / 6;
                if (id % 2 == 0)
                    ans = (ans + r) % mod;
                else
                    ans = (ans + (ll)(P - 1) * r) % mod;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}