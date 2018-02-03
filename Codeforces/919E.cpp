#include <iostream>

using ll = long long;

int power_mod(int a, int n, int p) {
    int ret = 1;
    while (n) {
        if (n & 1) ret = (ll) ret * a % p;
        a = (ll) a * a % p;
        n >>= 1;
    }
    return ret;
}

int inverse(int a, int m) {
    return a == 1 ? 1 : (ll) inverse(m % a, m) * (m - m / a) % m;
}

int main() {
    int a, b, p;
    ll x;
    std::cin >> a >> b >> p >> x;
    ll ans = 0, mod = (ll) p * (p - 1);
    for (int r1 = 0; r1 < p - 1; ++r1) {
        int r2 = (ll) b * inverse(power_mod(a, r1, p), p) % p;
        ll s = ((ll) r1 * p + (ll) r2 * (p - 1) % mod * (p - 1)) % mod;
        if (s == 0) s = mod;
        ans += x / mod + (s <= (x % mod));
    }
    std::cout << ans << std::endl;
    return 0;
}