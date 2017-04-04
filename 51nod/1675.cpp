#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int N = 100000;
int prime[N + 1], mu[N + 1];
int a[N + 1], b[N + 1];
int num[N + 1];

int main() {
    ios::sync_with_stdio(false);
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
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mu[i]) {
            ll tmp = 0;
            for (int j = i; j <= n; j += i) num[a[b[j]]]++;
            for (int j = i; j <= n; j += i) tmp += num[b[a[j]]];
            for (int j = i; j <= n; j += i) num[a[b[j]]]--;
            ans += mu[i] * tmp;
        }
    }
    cout << ans << endl;
    return 0;
}