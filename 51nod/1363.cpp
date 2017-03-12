#include <stdio.h>
const int maxn = 32000;
const int mod = 1000000007;
typedef long long ll;
int prime[maxn], inv[maxn];

int main() {
    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i < maxn / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int x = n, ans = 1;
        for (int i = 1; i <= prime[0]; i++) {
            if (prime[i] > x / prime[i]) break;
            if (x % prime[i] == 0) {
                int t = 1;
                while (x % prime[i] == 0) {
                    t *= prime[i];
                    x /= prime[i];
                }
                ans = ((ll) t * t % mod * prime[i] % mod + 1) * ans % mod *
                      inv[prime[i] + 1] % mod;
            }
        }
        if (x > 1) ans = ((ll) x * x - x + 1) % mod * ans % mod;
        ans = (ll)(ans + 1) * n % mod * inv[2] % mod;
        printf("%d\n", ans);
    }
    return 0;
}