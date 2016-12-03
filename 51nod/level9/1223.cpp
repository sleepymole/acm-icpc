#include<iostream>
#include<algorithm>
#include<vector>
#include<stdint.h>
using namespace std;
const int N = 316228;
int prime[N + 1], mu[N + 1];
vector<int>num[N + 1];

int64_t calc(int64_t l, int64_t r, int x) {
    int64_t ret = 0;
    ret += (r - l + 1) + mu[x] * (r / x - (l - 1) / x);
    for (int i = 0;i < num[x].size();i++) {
        ret += mu[num[x][i]] * (r / num[x][i] - (l - 1) / num[x][i]);
    }
    return ret;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    mu[1] = 1;
    for (int i = 2;i <= N;i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mu[i] = -1;
        }
        for (int j = 1;j <= prime[0] && i <= N / prime[j];j++) {
            prime[i*prime[j]] = 1;
            if (i%prime[j]) mu[i*prime[j]] = -mu[i];
            else break;
        }
        for (int j = i + i;j <= N;j += i) {
            num[j].push_back(i);
        }
    }
    int64_t n, ans = 0;
    cin >> n;
    for (int i = 2;i <= n / (i + 1);i++) {
        int j = i + 1;
        while ((j <= 2 * i - 1) && (j <= n / i / j)) {
            if (gcd(i, j) == 1) {
                ans += n / i / j;
            }
            j++;
        }
        int64_t k = max(1LL, n / i / (2 * i - 1)), l, r;
        for (;k <= n / i / j;k++) {
            l = max(1LL * j, n / i / (k + 1) + 1);
            r = min(2LL * i - 1, n / i / k);
            ans += k*calc(l, r, i);
        }
    }
    cout << ans << endl;
    return 0;
}