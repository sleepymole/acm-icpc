#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int P = 1000000007;

int power_mod(int a, int n) {
    int ret = 1;
    while (n) {
        if (n & 1) ret = (ll) ret * a % P;
        a = (ll) a * a % P;
        n >>= 1;
    }
    return ret;
}

int inv(int a) { return a == 1 ? 1 : (ll) inv(P % a) * (P - P / a) % P; }

int main() {
    int p, q, r, n;
    scanf("%d%d%d%d", &p, &q, &r, &n);
    int ans = 0;
    if (p == 1 && q == 1)
        ans = (ll)(n + 1) * n / 2 % P * 3 % P * r % P;
    else if (p == 1) {
        ans = 3LL * r % P *
              ((ll) q * (power_mod(q, n) - 1) % P * inv(q - 1) % P - n) % P *
              inv(q - 1) % P;
    } else if (q == 1) {
        ans = 3LL * r % P * inv(p - 1) % P *
              ((ll)(power_mod(p, n + 1) - 1) * inv(p - 1) % P - (n + 1)) % P;
    } else if (p == q) {
        ans = 3LL * r % P * inv(p - 1) % P *
              ((ll)(n + 1) * power_mod(p, n) % P -
               (ll)(power_mod(p, n + 1) - 1) * inv(p - 1) % P) %
              P;
    } else {
        int b = (ll) p * inv(q) % P;
        ans = 3LL * r % P * inv(p - 1) % P *
              ((ll) power_mod(q, n + 1) * (power_mod(b, n + 1) - 1) % P *
                   inv((p - q) % P + P) % P -
               (ll)(power_mod(q, n + 1) - 1) * inv(q - 1) % P) %
              P;
    }
    ans = (ans + P) % P;
    printf("%d\n", ans);
    return 0;
}