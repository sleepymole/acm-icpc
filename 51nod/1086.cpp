#include <iostream>
using namespace std;
const int maxn = 1001;
int w[maxn], p[maxn], dp[50010];

int main() {
    int N, W;
    cin >> N >> W;
    int tw, tp, c, k = 0;
    for (int i = 0; i < N; i++) {
        cin >> tw >> tp >> c;
        int base = 1;
        while (c > base) {
            k++;
            w[k] = base * tw;
            p[k] = base * tp;
            c -= base;
            base *= 2;
        }
        k++;
        w[k] = c * tw;
        p[k] = c * tp;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = W; j > 0; j--) {
            if (j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}