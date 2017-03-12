#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int maxn = 11;
int f[maxn][maxn], g[maxn][maxn], c[maxn][maxn];

int power_mod(int a, int n) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % mod;
        a = (ll) a * a % mod;
        n /= 2;
    }
    return r;
}

int main() {
    c[0][0] = 1;
    for (int i = 1; i <= 10; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            g[i][j] = power_mod(3, i * j);
        }
    }
    g[0][0] = 0;
    for (int n = 1; n <= 10; n++) {
        for (int m = 1; m <= 10; m++) {
            f[n][m] = (g[n][m] - g[n - 1][m]) % mod;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    f[n][m] = (f[n][m] -
                               (ll) c[n - 1][i - 1] * c[m][j] % mod * f[i][j] %
                                   mod * g[n - i][m - j] % mod) %
                              mod;
                    f[n][m] = (f[n][m] + mod) % mod;
                }
            }
        }
    }
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        printf("%d\n", f[n][m]);
    }
    return 0;
}