#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int inv = 500000004;

int main() {
    ll n;
    cin >> n;
    int ans = (n % mod) * (n % mod) % mod;
    int r = 1;
    while (r <= n / r)
        ans = (ans - n / r * r -
               ((n / r + n / (r + 1) + 1) % mod) *
                   ((n / r - n / (r + 1)) % mod) % mod * inv % mod * r % mod) %
              mod,
        r++;
    if (n / r < (r - 1)) ans = (ans + n / (r - 1) * (r - 1)) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}