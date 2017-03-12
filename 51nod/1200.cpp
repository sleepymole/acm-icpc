#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int P = 1000000007;
const int N = 1 << 16;
int prime[N + 1], f[N + 1];

int power_mod(int a, int n) {
    int r = 1;
    while (n) {
        if (n & 1) r = (ll) r * a % P;
        a = (ll) a * a % P;
        n >>= 1;
    }
    return r;
}

void transform(int x[], int n, int on) {
    on = on > 0 ? 1 : (P + 1) / 2;
    for (int h = 2; h <= n; h <<= 1) {
        for (int i = 0; i < n; i += h) {
            for (int k = i; k < i + h / 2; k++) {
                int u = x[k], t = x[k + h / 2];
                x[k] = (ll) on * (u + t) % P;
                x[k + h / 2] = (ll) on * (u - t + P) % P;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= m; i++) {
        if (!f[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i <= m / prime[j]; j++) {
            f[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
        f[i] ^= 1;
    }
    int len = 1;
    while (len < (m + 1)) len <<= 1;
    transform(f, len, 1);
    for (int i = 0; i < len; i++) {
        f[i] = power_mod(f[i], n);
    }
    transform(f, len, -1);
    cout << f[0] << endl;
    return 0;
}