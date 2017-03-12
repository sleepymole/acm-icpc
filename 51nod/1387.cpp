#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxBite = 17;
const int N = 1 << 17;
const int vol = 1 << 20;
int mod, G;

int inverse(int a, int p) {
    return a == 1 ? 1 : (ll) inverse(p % a, p) * (p - p / a) % p;
}

int power_mod(int a, int n, int p) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % p;
        a = (ll) a * a % p;
        n /= 2;
    }
    return r;
}

namespace NT {
const int maxn = 40000;
int prime[maxn], primeCnt;
bool notprime[maxn];
int factor[100][2];

void getPrime() {
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < maxn; i++) {
        if (!notprime[i]) {
            prime[primeCnt++] = i;
            if (i > maxn / i) continue;
            for (int j = i * i; j < maxn; j += i) {
                notprime[j] = true;
            }
        }
    }
}

int getFactor(int x) {
    int fatCnt = 0;
    for (int i = 0; i < primeCnt; i++) {
        if (prime[i] > x / prime[i]) break;
        if (x % prime[i] == 0) {
            factor[fatCnt][0] = prime[i];
            factor[fatCnt][1] = 0;
            while (x % prime[i] == 0) {
                factor[fatCnt][1]++;
                x /= prime[i];
            }
            fatCnt++;
        }
    }
    if (x > 1) {
        factor[fatCnt][0] = x;
        factor[fatCnt][1] = 1;
        fatCnt++;
    }
    return fatCnt;
}

int getPrimitiveRoot(int p) {
    getPrime();
    int n = getFactor(p - 1);
    for (int x = 2; x < p; x++) {
        bool found = true;
        for (int i = 0; i < n; i++) {
            if (power_mod(x, (p - 1) / factor[i][0], p) == 1) {
                found = false;
                break;
            }
        }
        if (found) return x;
    }
    return -1;
}
}

int wn[40];
void transform(int x[], int n, int on) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(x[i], x[j]);
        for (int k = n >> 1; (j ^= k) < k; k >>= 1)
            ;
    }
    for (int h = 2, d = 1; h <= n; h <<= 1, d++) {
        int e = wn[d + maxBite * (1 - on) / 2];
        for (int j = 0; j < n; j += h) {
            int w = 1;
            for (int k = j; k < j + h / 2; k++) {
                int u = x[k], t = (ll) w * x[k + h / 2] % mod;
                x[k] = ((ll) u + t) % mod;
                x[k + h / 2] = ((ll) u - t + mod) % mod;
                w = (ll) w * e % mod;
            }
        }
    }
    if (on == -1) {
        int inv = inverse(n, mod);
        for (int i = 0; i < n; i++) {
            x[i] = (ll) x[i] * inv % mod;
        }
    }
}

void polynomial_inverse(int a[], int b[], int n) {
    static int tmp[N];
    int len = 1;
    while (len < n) len <<= 1;
    b[0] = inverse(a[0] % mod, mod);
    for (int h = 2; h <= len; h <<= 1) {
        int p = h << 1;
        for (int i = 0; i < h; i++) {
            tmp[i] = a[i];
            tmp[i + h] = 0;
        }
        transform(b, p, 1);
        transform(tmp, p, 1);
        for (int i = 0; i < p; i++) {
            b[i] = (ll)(2LL - (ll) tmp[i] * b[i] % mod + mod) * b[i] % mod;
        }
        transform(b, p, -1);
        memset(b + h, 0, h * sizeof(int));
    }
    memset(b + n, 0, (len - n) * sizeof(int));
}

int pool[vol], *tail = pool, *g[N];

inline int* tail_alloc(int len) {
    int* ret = tail;
    tail += len;
    return ret;
}

inline void tail_free(int len) {
    tail -= len;
    memset(tail, 0, len * sizeof(int));
}

void polynomial_mod(int a[], int n, int b[], int m) {
    static int a0[N], b0[N];
    int len = 1, t = n - m + 1, p = 1;
    while (p < n) p <<= 1;
    while (len < (t << 1)) len <<= 1;
    int maxlen = max(p, len);
    memset(a0, 0, maxlen * sizeof(int));
    memset(b0, 0, maxlen * sizeof(int));
    for (int i = 0; i < m; i++) {
        a0[i] = b[m - 1 - i];
    }
    polynomial_inverse(a0, b0, t);
    for (int i = 0; i < n; i++) {
        a0[i] = a[n - 1 - i];
    }
    memset(a0 + t, 0, (len - t) * sizeof(int));
    transform(a0, len, 1);
    transform(b0, len, 1);
    for (int i = 0; i < len; i++) {
        a0[i] = (ll) a0[i] * b0[i] % mod;
    }
    transform(a0, len, -1);
    memset(a0 + t, 0, (p - t) * sizeof(int));
    reverse(a0, a0 + t);
    memcpy(b0, b, m * sizeof(int));
    memset(b0 + m, 0, (p - m) * sizeof(int));
    transform(a0, p, 1);
    transform(b0, p, 1);
    for (int i = 0; i < p; i++) {
        a0[i] = (ll) a0[i] * b0[i] % mod;
    }
    transform(a0, p, -1);
    for (int i = 0; i < m; i++) {
        b[i] = ((ll) a[i] - a0[i] + mod) % mod;
    }
}

void calculate(int l, int r, int f[]) {
    if (l == r) {
        f[0] = l;
        f[1] = 1;
        return;
    }
    int len = 1;
    while (len < (r - l + 2)) len <<= 1;
    int* g = tail_alloc(len);
    int mid = (l + r) / 2;
    calculate(l, mid, f);
    calculate(mid + 1, r, g);
    transform(f, len, 1);
    transform(g, len, 1);
    for (int i = 0; i < len; i++) {
        f[i] = (ll) f[i] * g[i] % mod;
    }
    transform(f, len, -1);
    tail_free(len);
}

void build(int o, int l, int r, int n) {
    if (l == r) {
        g[o] = tail_alloc(2);
        g[o][0] = (ll) l * (mod - n) % mod;
        g[o][1] = 1;
        return;
    }
    int len = 1;
    while (len < (r - l + 2)) len <<= 1;
    g[o] = tail_alloc(len);
    int mid = (l + r) / 2;
    build(2 * o + 1, l, mid, n);
    build(2 * o + 2, mid + 1, r, n);
    int* f = tail_alloc(len);
    memcpy(f, g[2 * o + 1], (mid - l + 2) * sizeof(int));
    memcpy(g[o], g[2 * o + 2], (r - mid + 1) * sizeof(int));
    transform(f, len, 1);
    transform(g[o], len, 1);
    for (int i = 0; i < len; i++) {
        g[o][i] = (ll) f[i] * g[o][i] % mod;
    }
    transform(g[o], len, -1);
    tail_free(len);
}

int h[N];
void evaluation(int o, int l, int r) {
    if (l == r) {
        h[l] = g[o][0];
        return;
    }
    int len = 1;
    while (len < r - l + 1) len <<= 1;
    int mid = (l + r) / 2;
    polynomial_mod(g[o], r - l + 2, g[2 * o + 1], mid - l + 2);
    polynomial_mod(g[o], r - l + 2, g[2 * o + 2], r - mid + 1);
    evaluation(2 * o + 1, l, mid);
    evaluation(2 * o + 2, mid + 1, r);
}

int f[N];
int factorial(int n) {
    if (n == 1) return 1;
    if (n == 2) return 24;
    calculate(1, n, f);
    build(0, 1, n - 1, n);
    polynomial_mod(f, n + 1, g[0], n);
    evaluation(0, 1, n - 1);
    int ans = f[0];
    for (int i = 1; i < n; i++) {
        ans = (ll) ans * h[i] % mod;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d%d", &n, &mod);
    G = NT::getPrimitiveRoot(mod);
    for (int h = 2, d = 1; h <= N; h <<= 1, d++) {
        wn[d] = power_mod(G, (mod - 1) / h, mod);
        wn[d + maxBite] = inverse(wn[d], mod);
    }
    int k = sqrt(n);
    int ans = factorial(k);
    for (int i = k * k + 1; i <= n; i++) {
        ans = (ll) ans * i % mod;
    }
    if (n % 2) ans = (ll) ans * inverse(2, mod) % mod;
    printf("%d\n", ans);
    return 0;
}