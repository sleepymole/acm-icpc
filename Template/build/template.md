# Template
####math
* count_prime.cpp
``` cpp
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2000000, P = 510510, Q = 92160;
int prime[N + 1], pi[N + 1], e[P];

void init() {
    for (int i = 2; i <= N; i++) {
        if (!prime[i])
            prime[++prime[0]] = i, pi[i] = pi[i - 1] + 1;
        else
            pi[i] = pi[i - 1];
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < P; i++) e[i] = i;
    for (int i = 1; i <= 7; i++) {
        for (int j = P - 1; j >= 0; j--) {
            e[j] -= e[j / prime[i]];
        }
    }
}

ll get_phi(ll m, int n) {
    if (n == 7) return m / P * Q + e[m % P];
    if (m < prime[n]) return 1;
    if (m <= N && m <= (ll) prime[n] * prime[n] * prime[n]) {
        ll ans = pi[m] - n + 1;
        int l = n + 1, r = pi[(int) sqrt(m + 0.1)];
        for (int i = l; i <= r; i++) ans += pi[m / prime[i]] - i + 1;
        return ans;
    }
    return get_phi(m, n - 1) - get_phi(m / prime[n], n - 1);
}

// prime-counting function
ll get_pi(ll m) {
    if (m <= N) return pi[m];
    int n = pi[(int) cbrt(m - 0.1) + 1];
    ll ans = get_phi(m, n) + n - 1;
    for (int i = n + 1, l = pi[(int) sqrt(m + 0.1)]; i <= l; i++)
        ans -= get_pi(m / prime[i]) - i + 1;
    return ans;
}

// the nth prime, 1<=n<=1e9
bool f[1000010];
ll get_pn(ll n) {
    if (n <= prime[0]) return prime[n];
    ll x = n * (log(n) + log(log(n)) - 1) + n * (log(log(n)) - 2) / log(n) -
           6 * n / 1000;
    ll y = n * (log(log(n))) * (log(log(n))) / log(n) / log(n);
    y = min(y, ll(3500000));
    ll l = x, r = x + y, flag = 0;
    for (int i = 0; i < 2; i++) {
        ll m = (l + r) >> 1;
        ll pm = get_pi(m);
        if (pm >= n) {
            r = m;
            flag = 0;
        } else {
            l = m + 1;
            flag = pm;
        }
    }
    ll count = flag ? flag : get_pi(l - 1);
    for (int i = 1, right = pi[(int) sqrt(r + 0.1)]; i <= right; i++) {
        for (int j = ((l - 1) / prime[i] + 1) * prime[i] - l; j <= r - l;
             j += prime[i]) {
            f[j] = true;
        }
    }
    for (int i = 0; i <= r - l; i++) {
        if (!f[i]) {
            count++;
            if (count == n) return i + l;
        }
    }
    return -1;
}

int main() {
    init();
    ll n;
    while (cin >> n) cout << get_pn(n) << endl;
    return 0;
}
```



* poly_double.cpp
``` cpp
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
const double PI = acos(-1.0);

struct Complex {
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
    Complex operator+(const Complex& rhs) const {
        return Complex(x + rhs.x, y + rhs.y);
    }
    Complex operator-(const Complex& rhs) const {
        return Complex(x - rhs.x, y - rhs.y);
    }
    Complex operator*(const Complex& rhs) const {
        return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
    }
};

//快速傅里叶变换(浮点型)
void transform(Complex x[], int n, int on) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(x[i], x[j]);
        for (int k = n >> 1; (j ^= k) < k; k >>= 1);
    }
    for (int h = 2; h <= n; h <<= 1) {
        Complex z(1.0 - cos(2 * PI / h), -sin(on * 2 * PI / h));
        for (int j = 0; j < n; j += h) {
            Complex e(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = x[k], t = e * x[k + h / 2];
                x[k] = u + t;
                x[k + h / 2] = u - t;
                e = e - e * z;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < n; i++) {
            x[i].x = x[i].x / n;
        }
    }
}

int main() {
    int startTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);

    int endTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);
    cout << (endTime - startTime) << "ms" << endl;
    return 0;
}
```



* merge_prime.cpp
``` cpp
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int p[] = {25 * (1 << 22) + 1, 5 * (1 << 25) + 1, 7 * (1 << 26) + 1};
const int G = 3;
const int N = 1 << 17;
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

void merge(int &x, int &y, int &z) {
    sum = (x * wy[0] + y * wy[1] + z * wy[2]) % M;
    x = y = z = sum % mod;
}

void merge_initial2() {
    wy[0] = 34952532LL * p[1];
    wy[1] = 111848110LL * p[0];
    M = (__int128) p[0] * p[1];
}

void merge2(int &x, int &y) {
    sum = (x * wy[0] + y * wy[1]) % M;
    x = y = sum % mod;
}

int main() {
    merge_initial();
    return 0;
}
```



* poly_int.cpp
``` cpp
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
```



* miller_rabin.cpp
``` cpp
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long int64;
typedef __int128 int128;

int64 power_mod(int64 a, int64 n, int64 m) {
    int64 r = 1;
    while (n) {
        if (n % 2) r = (int128) r * a % m;
        a = (int128) a * a % m;
        n /= 2;
    }
    return r;
}

bool witness(int64 a, int64 p) {
    int64 q = p - 1, k = 0;
    while (q % 2 == 0) {
        k++;
        q /= 2;
    }
    int64 v = power_mod(a, q, p);
    if (v == 1 || v == p - 1) return false;
    while (k--) {
        v = (int128) v * v % p;
        if (v == p - 1) return false;
    }
    return true;
}

bool miller_rabin(int64 p) {
    if (p == 2) return true;
    if (p == 1 || p % 2 == 0) return false;
    for (int i = 0; i < 50; i++) {
        int64 a = rand() % (p - 1) + 1;
        if (witness(a, p)) return false;
    }
    return true;
}

int main() {
    int64 p;
    while (cin >> p) {
        if (miller_rabin(p))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
```



* pollard_rho.cpp
``` cpp
#include <iostream>
#include <vector>
using namespace std;
typedef long long int64;
typedef __int128 int128;

int64 power_mod(int64 a, int64 n, int64 m) {
    int64 r = 1;
    while (n) {
        if (n % 2) r = (int128) r * a % m;
        a = (int128) a * a % m;
        n /= 2;
    }
    return r;
}

bool witness(int64 a, int64 p) {
    int64 q = p - 1, k = 0;
    while (q % 2 == 0) {
        k++;
        q /= 2;
    }
    int64 v = power_mod(a, q, p);
    if (v == 1 || v == p - 1) return false;
    while (k--) {
        v = (int128) v * v % p;
        if (v == p - 1) return false;
    }
    return true;
}

bool miller_rabin(int64 p) {
    if (p == 2) return true;
    if (p == 1 || p % 2 == 0) return false;
    for (int i = 0; i < 50; i++) {
        int64 a = rand() % (p - 1) + 1;
        if (witness(a, p)) return false;
    }
    return true;
}

int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }

int64 pollard_rho(int64 n) {
    int64 k = 2, x0 = 1, y = x0;
    int64 c = rand() % (n - 1) + 1;
    for (int i = 2;; i++) {
        x0 = ((int128) x0 * x0 + c) % n;
        int64 s = gcd(abs(y - x0), n);
        if (s != 1 && s != n) return s;
        if (y == x0) return n;
        if (i == k) y = x0, k <<= 1;
    }
}

vector<int64> v;
void factor(int64 n) {
    if (miller_rabin(n)) {
        v.push_back(n);
        return;
    }
    int64 d = n;
    while (d == n) d = pollard_rho(n);
    factor(d);
    factor(n / d);
}

int main() {
    int64 n;
    while (cin >> n) {
        v.clear();
        factor(n);
    }
    return 0;
}
```



####other
* io.cpp
``` cpp
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

#define BUF_SIZE 4096

struct {
    int cur, eof;
    char buf[BUF_SIZE];
    char next_char() {
        if (cur == BUF_SIZE) {
            if (eof) return -1;
            int bytes = fread(buf, 1, BUF_SIZE, stdin);
            if (bytes < BUF_SIZE) {
                memset(buf + bytes, -1, BUF_SIZE - bytes);
                buf[bytes] = -1;
                eof = 1;
            }
            cur = 0;
        }
        return buf[cur++];
    }
    int next_int() {
        int x = 0;
        char ch = next_char();
        while (ch < '0' || ch > '9') {
            if (ch == -1) return 0;
            ch = next_char();
        }
        while (ch >= '0' && ch <= '9') {
            x = (x << 3) + (x << 1) + ch - '0';
            ch = next_char();
        }
        return x;
    }
} IO = {BUF_SIZE};

void write(int n) {
    if (n >= 10) write(n / 10);
    putchar(n % 10 + '0');
}

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int startTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);
    int n = IO.next_int();
    cout << n << endl;
    int endTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);
    cout << (endTime - startTime) << "ms" << endl;
    return 0;
}

```



* suffix_array.cpp
``` cpp
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXS = 1010;
char str[MAXS];

int sa[MAXS], rk[MAXS], height[MAXS];
void build_sa(int n, int m) {
    static int sa2[MAXS], b[MAXS];
    memset(b, 0, m * sizeof(int));
    for (int i = 0; i < n; i++) b[rk[i]]++;
    for (int i = 1; i < m; i++) b[i] += b[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--b[rk[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        for (int i = n - k; i < n; i++) sa2[i + k - n] = i;
        for (int i = 0, p = k; i < n; i++)
            if (sa[i] >= k) sa2[p++] = sa[i] - k;
        memset(b, 0, m * sizeof(int));
        for (int i = 0; i < n; i++) b[rk[sa2[i]]]++;
        for (int i = 1; i < m; i++) b[i] += b[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--b[rk[sa2[i]]]] = sa2[i];
        memcpy(b, rk, n * sizeof(int));
        for (int i = 1, p = 1; i < n; i++) {
            int x = sa[i - 1] + k < n ? b[sa[i - 1] + k] : 0;
            int y = sa[i] + k < n ? b[sa[i] + k] : 0;
            rk[sa[i]] = b[sa[i - 1]] == b[sa[i]] && x == y ? p - 1 : p++;
        }
        rk[sa[0]] = 0, m = rk[sa[n - 1]] + 1;
        if (m == n) break;
    }
    for (int i = 0, k = 0; i < n - 1; i++) {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (str[i + k] == str[j + k]) k++;
        height[rk[i]] = k;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++) rk[i] = str[i];
        rk[len] = 0;
        build_sa(len + 1, 128);
        int ans = 0;
        for (int i = 1; i <= len; i++) ans += len - sa[i] - height[i];
        printf("%d\n", ans);
    }
    return 0;
}
```



* string.cpp
``` cpp
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2000010;

void pre_kmp(char x[], int n, int fail[]) {
    int i = 0, j = fail[0] = -1;
    while (i < n) {
        while (-1 != j && x[i] != x[j]) j = fail[j];
        if (x[++i] == x[++j])
            fail[i] = fail[j];
        else
            fail[i] = j;
    }
}

int p[MAXN];
int manacher(const char* str) {
    static char s[MAXN];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        s[2 * i] = '#';
        s[2 * i + 1] = str[i];
    }
    s[2 * len] = '#';
    len = 2 * len + 1;
    int pos = 0, max_right = 0, res = 0;
    for (int i = 0; i < len; i++) {
        p[i] = 1;
        if (i < max_right) p[i] = min(p[2 * pos - i], max_right - i + 1);
        while (i - p[i] >= 0 && i + p[i] < len && s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if (p[i] + i - 1 > max_right) {
            max_right = p[i] + i - 1;
            pos = i;
        }
        res = max(res, p[i]);
    }
    return res - 1;
}

int main() {
    cout << manacher("abcdabc") << endl;
    return 0;
}
```



