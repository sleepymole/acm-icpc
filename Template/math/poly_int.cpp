#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1 << 17;
const int G = 3;

//求a关于m的逆,要求a>0&&a<m&&(a,m)=1
int inverse(int a, int m) {
    return a == 1 ? 1 : (ll) inverse(m % a, m) * (m - m / a) % m;
}

int power_mod(int a, int n) {
    int r = 1, k = n > 0 ? n : -n;
    while (k) {
        if (k % 2) r = (ll) r * a % mod;
        a = (ll) a * a % mod;
        k /= 2;
    }
    if (n < 0) r = inverse(r, mod);
    return r;
}

//快速数论变换,n必须为2^k形式
void transform(int x[], int n, int on) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(x[i], x[j]);
        for (int k = n >> 1; (j ^= k) < k; k >>= 1)
            ;
    }
    for (int h = 2; h <= n; h <<= 1) {
        int wn = power_mod(G, on * (mod - 1) / h);
        for (int j = 0; j < n; j += h) {
            int w = 1;
            for (int k = j; k < j + h / 2; k++) {
                int u = x[k], t = (ll) w * x[k + h / 2] % mod;
                x[k] = (u + t) % mod;
                x[k + h / 2] = (u - t + mod) % mod;
                w = (ll) w * wn % mod;
            }
        }
    }
    if (on == -1) {
        int Inv = inverse(n % mod, mod);
        for (int i = 0; i < n; i++) {
            x[i] = (ll) x[i] * Inv % mod;
        }
    }
}

// b数组需要初始化
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

//多项式求对数,结果存放在b中,b数组需要初始化
void polynomial_logarithm(int a[], int b[], int n) {
    static int tmp[N];
    int p = 1;
    while (p < (n << 1)) p <<= 1;
    memset(tmp, 0, p * sizeof(int));
    memset(b, 0, p * sizeof(int));
    polynomial_inverse(a, tmp, n);
    memcpy(b, a, n * sizeof(int));
    for (int i = 0; i < n - 1; i++) {  //求导
        b[i] = (ll) b[i + 1] * (i + 1) % mod;
    }
    b[n - 1] = 0;
    transform(tmp, p, 1);
    transform(b, p, 1);
    for (int i = 0; i < p; i++) {
        b[i] = (ll) tmp[i] * b[i] % mod;
    }
    transform(b, p, -1);
    for (int i = n - 1; i > 0; i--) {
        b[i] =
            (ll) b[i - 1] * inverse(i, mod) % mod;  //可以把1-n关于mod的逆预处理
    }
    b[0] = 0;  //视情况而定
    memset(b + n, 0, (p - n) * sizeof(int));
}

void polynomial_exponent(int a[], int b[], int n) {
    static int tmp[N];
    int len = 1;
    b[0] = 1;
    while (len < n) len <<= 1;
    for (int h = 2; h <= len; h <<= 1) {
        int p = h << 1;
        polynomial_logarithm(b, tmp, h);
        for (int i = 0; i < h; i++) {
            tmp[i] = ((a[i] - tmp[i]) % mod + mod) % mod;
        }
        tmp[0]++;
        transform(b, p, 1);
        transform(tmp, p, 1);
        for (int i = 0; i < p; i++) {
            b[i] = (ll) b[i] * tmp[i] % mod;
        }
        transform(b, p, -1);
        memset(b + h, 0, h * sizeof(int));
    }
    memset(b + n, 0, (len - n) * sizeof(int));
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

int main() {
    int startTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);

    int endTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);
    cout << (endTime - startTime) << "ms" << endl;
    return 0;
}