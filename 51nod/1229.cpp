#include <stdint.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int P = 1000000007;
const int N = 20010;

int power_mod(int a, int n) {
    int r = 1;
    while (n) {
        if (n & 1) r = (int64_t) r * a % P;
        a = (int64_t) a * a % P;
        n >>= 1;
    }
    return r;
}

int inverse(int a) {
    return a == 1 ? 1 : (int64_t) inverse(P % a) * (P - P / a) % P;
}

int f[N + 5], g[N + 5], inv[N + 5], prime[N + 5];
int a[N + 5], b[N + 5], fac_inv[N + 5];
int main() {
    fac_inv[0] = fac_inv[1] = inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (int64_t) inv[P % i] * (P - P / i) % P;
        fac_inv[i] = (int64_t) fac_inv[i - 1] * inv[i] % P;
    }
    int T;
    cin >> T;
    while (T--) {
        int64_t k, n, r;
        cin >> n >> k >> r;
        r %= P;
        int d = k + 1;
        memset(f, 0, (d + 1) * sizeof(int));
        f[1] = 1;
        prime[0] = 0;
        for (int i = 2; i <= d; i++) {
            if (!f[i]) {
                prime[++prime[0]] = i;
                f[i] = power_mod(i, k);
            }
            for (int j = 1; j <= prime[0] && i <= d / prime[j]; j++) {
                f[i * prime[j]] = (int64_t) f[i] * f[prime[j]] % P;
                if (i % prime[j] == 0) break;
            }
        }
        if (r == 1) {
            for (int i = 1; i <= d; i++) {
                f[i] += f[i - 1];
                if (f[i] >= P) f[i] -= P;
            }
            if (n <= d) {
                cout << f[n] << endl;
                continue;
            }
            n %= P;
            a[0] = 1;
            b[0] = 1;
            for (int i = 1; i <= d + 1; i++) {
                a[i] = (int64_t) a[i - 1] * (n - i + 1) % P;
                b[i] = (int64_t) b[i - 1] * (n - d + i - 1) % P;
            }
            int ans = 0;
            for (int j = 0; j <= d; j++) {
                int tmp = (int64_t) a[j] * b[d - j] % P * fac_inv[d - j] % P *
                          fac_inv[j] % P * f[j] % P;
                if ((d - j) & 1) tmp = (P - tmp) % P;
                ans = (ans + tmp) % P;
            }
            cout << ans << endl;
        } else if (r > 1) {
            memset(b, 0, (d + 1) * sizeof(int));
            a[0] = 1;
            d = k;
            for (int i = 1; i <= d + 1; i++) {
                a[i] = (int64_t) a[i - 1] * (d - i + 2) % P * inv[i] % P;
                a[i] = P - a[i];
            }
            int rinv = inverse(r);
            for (int i = d + 1; i > 0; i--) {
                a[i - 1] = (a[i - 1] + (int64_t) a[i] * rinv) % P;
                b[i - 1] = (b[i - 1] + (int64_t) a[i] * f[i] + b[i]) % P;
            }
            g[0] = (int64_t)(P - b[0]) * inverse(a[0]) % P;
            for (int i = 1; i <= d; i++) {
                g[i] = ((int64_t) g[i - 1] * rinv + f[i]) % P;
            }
            int R = power_mod(r, n % (P - 1));
            if (n <= d) {
                int ans = ((int64_t) R * g[n] - g[0]) % P;
                ans = (ans + P) % P;
                cout << ans << endl;
                continue;
            }
            n %= P;
            a[0] = 1;
            b[0] = 1;
            for (int i = 1; i <= d + 1; i++) {
                a[i] = (int64_t) a[i - 1] * (n - i + 1) % P;
                b[i] = (int64_t) b[i - 1] * (n - d + i - 1) % P;
            }
            int ans = 0;
            for (int j = 0; j <= d; j++) {
                int tmp = (int64_t) a[j] * b[d - j] % P * fac_inv[d - j] % P *
                          fac_inv[j] % P * g[j] % P;
                if ((d - j) & 1) tmp = (P - tmp) % P;
                ans = (ans + tmp) % P;
            }
            ans = ((int64_t) R * ans - g[0]) % P;
            ans = (ans + P) % P;
            cout << ans << endl;
        } else {
            puts("0");
        }
    }
    return 0;
}