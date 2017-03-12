#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int maxn = 10000010;
bool notprime[maxn];
int divisor[maxn];

void getPrime() {
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < maxn; i++) {
        if (!notprime[i]) {
            if (i > maxn / i) continue;
            for (int j = i * i; j < maxn; j += i) {
                divisor[j] = i;
                notprime[j] = true;
            }
        }
    }
}

int power_mod(int a, int n) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % mod;
        a = (ll) a * a % mod;
        n /= 2;
    }
    return r;
}

int x[maxn], y[maxn];
int main() {
    getPrime();
    ll m, x1, a, b, c, N = 1, Q = 1, M = 1;
    cin >> m >> x1 >> a >> b >> c;
    x[x1] = 1;
    y[1] = x1;
    int p;
    for (p = 1; p <= c; p++) {
        x1 = (a * x1 + b) % c + 1;
        if (x[x1]) break;
        x[x1] = 1;
        y[p + 1] = x1;
    }
    int sta = x1, t;
    for (t = 1; t <= p; t++) {
        if (y[t] == sta) break;
        N = N * y[t] % mod;
    }
    m -= (t - 1);
    ll q = p - t + 1;
    for (int i = t; i <= p; i++) {
        ll k = m / q;
        if (i - t + 1 <= (m % q)) {
            k++;
            N = N * y[i] % mod;
        }
        M = M * y[i] % mod;
        x[y[i]] = k % mod;
    }
    N = N * power_mod(M, (m / q) % (mod - 1)) % mod;
    for (int i = c; i > 1; i--) {
        if (x[i] == 0) continue;
        if (!notprime[i]) {
            Q = Q * (x[i] + 1) % mod;
            continue;
        }
        x[divisor[i]] = (x[divisor[i]] + x[i]) % mod;
        x[i / divisor[i]] = (x[i / divisor[i]] + x[i]) % mod;
    }
    int ans = N * Q % mod;
    cout << ans << endl;
    return 0;
}