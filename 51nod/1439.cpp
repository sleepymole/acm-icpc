#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 500000;
int prime[N + 1], f[N + 1], a[N + 1], mu[N + 1];

int main() {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                mu[i * prime[j]] = -mu[i];
            } else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    int n, q, x;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    while (q--) {
        scanf("%d", &x);
        int sgn = a[x] > 0 ? 1 : -1;
        int y = abs(a[x]);
        if (y == 1) {
            if (sgn == 1)
                ans += f[1];
            else
                ans -= f[1] - 1;
            f[1] += sgn;
        } else {
            for (int j = 1; j <= y / j; j++) {
                if (y % j == 0) {
                    f[j] += sgn;
                    ans += sgn * f[j] * mu[j];
                    if (j * j != y) {
                        f[y / j] += sgn;
                        ans += sgn * f[y / j] * mu[y / j];
                    }
                }
            }
        }
        a[x] = -a[x];
        printf("%lld\n", ans);
    }
    return 0;
}