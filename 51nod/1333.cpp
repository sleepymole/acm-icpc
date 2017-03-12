#include <stdint.h>
#include <iostream>
using namespace std;
const int N = 5000000;
int prime[N + 1], notprime[N + 1], f[N + 1];
int64_t sum[N + 1];

int main() {
    notprime[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!notprime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 2; i * i <= N; i++) {
        for (int j = i; i * j <= N; j++) {
            if (notprime[i + j - 1]) {
                f[i * j] = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (f[i - 1] == 0 && notprime[i - 1])
            sum[i] = sum[i - 1] + i;
        else
            sum[i] = sum[i - 1];
    }
    int T;
    cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;
        int64_t ans = sum[R] - sum[L - 1];
        if (L <= 2) ans -= 2;
        cout << ans << endl;
    }
    return 0;
}