#include <iostream>
using namespace std;
typedef long long ll;
const int N = 10000000;
int prime[N + 1], mu[N + 1], f[N + 1];
int t[N + 1];

int F(int n) {
    if (n <= N) return t[n];
    int ret = n;
    for (int d = 1; d * d <= n; d++) ret -= mu[d] * (n / d / d);
    return ret;
}

ll calc(int n) {
    ll ret = 0;
    int r;
    for (r = 1; r * r <= n; r++) {
        ret += (ll) f[r] * (n / r) + (ll)(F(n / r) - F(n / (r + 1))) * r;
    }
    if (n / r < r - 1) ret -= (ll) f[r - 1] * (n / (r - 1));
    return ret;
}

int main() {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
        f[i] = 1 - mu[i] * mu[i];
        t[i] = t[i - 1] + f[i];
    }
    int a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1) << endl;
    return 0;
}