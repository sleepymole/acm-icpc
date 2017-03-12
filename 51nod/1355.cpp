#include <iostream>
using namespace std;
typedef long long ll;
const int P = 1000000007;
const int maxN = 1000000;
int f[maxN + 1], a[maxN + 1];

int power_mod(int a, int n) {
    int r = 1;
    while (n) {
        if (n & 1) r = (ll) r * a % P;
        a = (ll) a * a % P;
        n >>= 1;
    }
    return r;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int n, x;
    scanf("%d", &n);
    int N = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > N) N = x;
        a[x] = 1;
    }
    f[1] = f[2] = 1;
    for (int i = 3; i <= N; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % P;
    }
    int ans = 1;
    for (int i = N; i >= 1; i--) {
        for (int j = i; j <= N; j += i) {
            if (a[j]) {
                a[i] = 1;
                break;
            }
        }
        if (a[i] == 0) continue;
        for (int j = i + i; j <= N; j += i) {
            a[i] = (a[i] - a[j]) % (P - 1);
        }
        a[i] = (a[i] + P - 1) % (P - 1);
        ans = (ll) ans * power_mod(f[i], a[i]) % P;
    }
    cout << ans << endl;
    return 0;
}