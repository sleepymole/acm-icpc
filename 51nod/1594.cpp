#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2000000;
int prime[N + 1], euler[N + 1];
ll f[N + 1], c[N + 1];

int main() {
    euler[1] = 1;
    f[1] = 1;
    for (int i = 1; i <= N; i++) f[i] = 1;
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            euler[i] = i - 1;
            f[i] = i - 2;
        }
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                euler[i * prime[j]] = euler[i] * prime[j];
                if (i / prime[j] % prime[j])
                    f[i * prime[j]] =
                        f[i / prime[j]] * (prime[j] - 1) * (prime[j] - 1);
                else
                    f[i * prime[j]] = f[i] * prime[j];
                break;
            } else {
                euler[i * prime[j]] = euler[i] * (prime[j] - 1);
                f[i * prime[j]] = f[i] * (prime[j] - 2);
            }
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        memset(c + 1, 0, n * sizeof(ll));
        for (int i = 1; i <= n; i++) {
            c[euler[i]]++;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = i; j <= n; j += i) {
                sum += c[j];
            }
            ans += f[i] * sum * sum;
        }
        printf("%lld\n", ans);
    }
    return 0;
}