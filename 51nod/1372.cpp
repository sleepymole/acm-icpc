#include <stdint.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int P = 1000000007;
const int N = 100000;
int prime[N + 1], f[N + 1], inv[N + 1];

int power_mod(int a, int n) {
    int r = 1;
    while (n) {
        if (n & 1) r = (int64_t) r * a % P;
        a = (int64_t) a * a % P;
        n >>= 1;
    }
    return r;
}

void calc(int l, int r) {
    if (l > r) return;
    for (int i = l; i <= r; i++) {
        int x = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (x / prime[j] < prime[j]) break;
            if (x % prime[j] == 0) {
                while (x % prime[j] == 0) {
                    x /= prime[j];
                    f[j]++;
                }
            }
        }
        if (x > 1) {
            x = lower_bound(prime + 1, prime + 1 + prime[0], x) - prime;
            f[x]++;
        }
    }
}

int main() {
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (int64_t) inv[P % i] * (P - P / i) % P;
    }
    int ans[20];
    for (int i = 0; i < 20; i++) {
        ans[i] = 1;
    }
    map<int, int> mp;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x;
        cin >> x;
        mp[x] = i;
    }
    int pre = 2;
    for (auto x : mp) {
        calc(pre + 1, x.first);
        pre = x.first;
        for (int i = 1; i <= prime[0]; i++) {
            if (prime[i] > pre) break;
            if (f[i])
                ans[x.second] = (int64_t) ans[x.second] *
                                power_mod(prime[i], f[i] - 1) % P *
                                ((f[i] + 1) * (prime[i]) - f[i]) % P;
        }
        ans[x.second] = (ans[x.second] + P) % P;
    }
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": " << ans[i] << endl;
    }
    return 0;
}