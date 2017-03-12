#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int p[] = {25 * (1 << 22) + 1, 5 * (1 << 25) + 1, 7 * (1 << 26) + 1};
const int N = 1 << 12, G = 3;
__int128 M, wy[3], sum;

void merge_initial() {
    ll w[3], y[3];
    w[0] = (ll) p[1] * p[2];
    w[1] = (ll) p[0] * p[2];
    w[2] = (ll) p[0] * p[1];
    y[0] = 803507;
    y[1] = 12427566;
    y[2] = -38396896;
    M = (__int128) p[0] * p[1] * p[2];
    for (int s = 0; s < 3; s++) {
        wy[s] = (__int128) w[s] * y[s] % M;
        wy[s] = (wy[s] + M) % M;
    }
}

inline void merge(int &x, int &y, int &z) {
    sum = (x * wy[0] + y * wy[1] + z * wy[2]) % M % mod;
    x = y = z = sum;
}

int inverse(int a, int m) {
    return a == 1 ? 1 : (ll) inverse(m % a, m) * (m - m / a) % m;
}

int power_mod(int a, int n, int p) {
    int r = 1, k = n > 0 ? n : -n;
    while (k) {
        if (k % 2) r = (ll) r * a % p;
        a = (ll) a * a % p;
        k /= 2;
    }
    if (n < 0) r = inverse(r, p);
    return r;
}

void transform(int x[], int n, int on, int p) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(x[i], x[j]);
        for (int k = n >> 1; (j ^= k) < k; k >>= 1)
            ;
    }
    for (int h = 2; h <= n; h <<= 1) {
        int wn = power_mod(G, on * (p - 1) / h, p);
        for (int j = 0; j < n; j += h) {
            int w = 1;
            for (int k = j; k < j + h / 2; k++) {
                int u = x[k], t = (ll) w * x[k + h / 2] % p;
                x[k] = (u + t) % p;
                x[k + h / 2] = (u - t + p) % p;
                w = (ll) w * wn % p;
            }
        }
    }
    if (on == -1) {
        int inv = inverse(n % p, p);
        for (int i = 0; i < n; i++) {
            x[i] = (ll) x[i] * inv % p;
        }
    }
}

void polynomial_inverse(int a[], int b[N], int n) {
    static int T[3][N];
    static int tmp[N];
    int len = 1;
    while (len < n) len <<= 1;
    T[2][0] = T[1][0] = T[0][0] = b[0] = 1;
    for (int h = 2; h <= len; h <<= 1) {
        for (int s = 0; s < 3; s++) {
            transform(T[s], h, 1, p[s]);
            for (int i = 0; i < h; i++) {
                T[s][i] = (ll) T[s][i] * T[s][i] % p[s];
            }
            transform(T[s], h, -1, p[s]);
        }
        for (int i = 0; i < h; i++) {
            merge(T[0][i], T[1][i], T[2][i]);
        }
        int t = h << 1;
        for (int s = 0; s < 3; s++) {
            copy(a, a + h, tmp);
            fill(tmp + h, tmp + t, 0);
            fill(T[s] + h, T[s] + t, 0);
            transform(tmp, t, 1, p[s]);
            transform(T[s], t, 1, p[s]);
            for (int i = 0; i < t; i++) {
                T[s][i] = (ll) T[s][i] * tmp[i] % p[s];
            }
            transform(T[s], t, -1, p[s]);
        }
        for (int i = 0; i < h; i++) {
            merge(T[0][i], T[1][i], T[2][i]);
        }
        for (int i = 0; i < h; i++) {
            b[i] = (2LL * b[i] - T[0][i] + mod) % mod;
            T[2][i] = T[1][i] = T[0][i] = b[i];
        }
        fill(b + h, b + t, 0);
        for (int s = 0; s < 3; s++) {
            fill(T[s] + h, T[s] + t, 0);
        }
    }
    fill(b + n, b + len, 0);
}

ll read() {
    ll x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void write(int n) {
    if (n >= 10) write(n / 10);
    putchar(n % 10 + '0');
}

int a[N], b[N], inv[N];

void initial() {
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
    }
    int r = 1;
    for (int i = 0; i < (N >> 1); i++) {
        r = (ll) r * (i + 1) % mod;
        a[i] = inverse(r, mod);
    }
    polynomial_inverse(a, b, N >> 1);
    r = 1;
    for (int i = 1; i < (N >> 1); i++) {
        r = (ll) r * i % mod;
        b[i] = (ll) b[i] * r % mod;
    }
}

int main() {
    merge_initial();
    initial();
    int t = read();
    while (t--) {
        ll n = read(), k = read();
        n = n % mod;
        ll ans = 0, r1 = 1, r2 = 1;
        for (int i = 1; i <= k + 1; i++) {
            r1 = r1 * (k + 2 - i) % mod * inv[i] % mod;
            r2 = r2 * (n + 1) % mod;
            ans = (ans + r1 * r2 % mod * b[k + 1 - i] % mod) % mod;
        }
        ans = ans * inv[k + 1] % mod;
        write(ans);
        putchar('\n');
    }
    return 0;
}