#include <iostream>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int inv = 500000004;

int kpow(int a, int n) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % mod;
        a = (ll) a * a % mod;
        n /= 2;
    }
    return r;
}
int main() {
    ll N;
    cin >> N;
    ll ans = (ll)(kpow(3, N + 1) - 1) * inv % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}