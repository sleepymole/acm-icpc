#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int N = 1000000;
int prime[N + 1];

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            int base = i, cnt = n / base * 2;
            while (base <= n / i) {
                base *= i;
                cnt += n / base * 2;
            }
            ans = (ll) ans * (cnt + 1) % mod;
        }
        for (int j = 1; j <= prime[0] && i <= n / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    ans = (ll)(ans + 1) * (mod + 1) / 2 % mod;
    cout << ans << endl;
    return 0;
}