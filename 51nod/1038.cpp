#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <hash_map>
using namespace std;
typedef long long ll;
const int N = 316228;
int prime[N + 1], ans[N + 1];

int power_mod(int a, int n, int p) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % p;
        a = (ll) a * a % p;
        n >>= 1;
    }
    return r;
}

int bsgs(int a, int b, int p) {
    if (b == 1) return 0;
    stdext::hash_map<int, int> Hash;
    int m = int(sqrt(1.0 * p) + 1);
    int base = b;
    for (int i = 0; i < m; i++) {
        Hash[base] = i;
        base = (ll) base * a % p;
    }
    base = power_mod(a, m, p);
    int now = 1;
    for (int i = 1; i <= m + 1; i++) {
        now = (ll) now * base % p;
        if (Hash.count(now)) {
            return i * m - Hash[now];
        }
    }
    return -1;
}

void exgcd(int a, int b, int &d, int &x, int &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

inline int read() {
    int x = 0;
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

int main() {
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int T = read();
    while (T--) {
        int p = read(), a = read(), b = read();
        int n = p - 1;
        int val[20], cnt = 0;
        for (int i = 1; i <= prime[0]; i++) {
            if (prime[i] > n) break;
            if (n % prime[i] == 0) {
                val[cnt++] = prime[i];
                while (n % prime[i] == 0) n /= prime[i];
            }
        }
        if (n > 1) val[cnt++] = n;
        int r = 1;
        for (; r < p; r++) {
            bool found = true;
            for (int i = 0; i < cnt; i++) {
                if (power_mod(r, (p - 1) / val[i], p) == 1) {
                    found = false;
                    break;
                }
            }
            if (found) break;
        }
        int t = bsgs(r, b, p);
        int x, y, d;
        exgcd(p - 1, a, d, x, y);
        if (t % d != 0)
            printf("No Solution\n");
        else {
            int m = (p - 1) / d;
            y = (ll) y * (t / d) % m;
            y = (y + m) % m;
            int base = power_mod(r, m, p);
            int now = power_mod(r, y, p);
            for (int i = 0; i < d; i++) {
                ans[i] = now;
                now = (ll) now * base % p;
            }
            sort(ans, ans + d);
            for (int i = 0; i < d; i++) {
                write(ans[i]);
                putchar(' ');
            }
            putchar('\n');
        }
    }
    return 0;
}