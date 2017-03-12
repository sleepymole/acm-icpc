#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int N = 10000000;

int prime[N + 1], S[N + 1];
void preS() {
    S[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            S[i] = -1;
        }
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                S[i * prime[j]] = 0;
                break;
            } else {
                S[i * prime[j]] = -S[i];
            }
        }
        S[i] = ((ll) i * S[i] + S[i - 1]) % mod;
    }
}

int calG(int n) {
    int ret = 0, r = 1;
    while (r * r <= n)
        ret = ((ll)(n / r + n / (r + 1) + 1) * (n / r - n / (r + 1)) / 2 % mod *
                   r +
               r * (n / r) + ret) %
              mod,
        r++;
    if (n / r < (r - 1)) ret = (ret - (r - 1) * (n / (r - 1))) % mod;
    return (ll) ret * ret % mod;
}

map<int, int> mp;
int calS(int n) {
    if (n <= N) return S[n];
    if (mp.count(n)) return mp[n];
    int ret = (mod + 1 - (ll)(n + n / 2 + 1) * (n - n / 2) / 2) % mod;
    int r = 2;
    while (r * r <= n)
        ret = ((ll) ret - (ll) r * calS(n / r) -
               (ll)(n / r + n / (r + 1) + 1) * (n / r - n / (r + 1)) / 2 % mod *
                   calS(r)) %
              mod,
        r++;
    if (n < r * (r - 1)) ret = ((ll)(r - 1) * calS(n / (r - 1)) + ret) % mod;
    return mp[n] = ret;
}

int main() {
    preS();
    int n;
    cin >> n;
    int ans = 0, r = 1;
    while (r * r <= n)
        ans = ((ll)(calS(r) - calS(r - 1)) * calG(n / r) +
               (ll)(calS(n / r) - calS(n / (r + 1))) * calG(r) + ans) %
              mod,
        r++;
    if (n / r < r - 1)
        ans = ((ll) ans - (ll)(calS(r - 1) - calS(r - 2)) * calG(n / (r - 1))) %
              mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}