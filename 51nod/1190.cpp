#include <stdint.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 1000000;
const int P = 1000000007, inv2 = (P + 1) >> 1;
int prime[N + 1], mu[N + 1];

int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int f(int n) {
    if (n <= N) return mu[n];
    int ret = 1;
    for (int i = 1; i <= prime[i] && prime[i] <= n / prime[i]; i++) {
        if (n % prime[i] == 0) {
            ret = (int64_t) ret * (P + 1 - prime[i]) % P;
            while (n % prime[i] == 0) n /= prime[i];
        }
    }
    if (n > 1) ret = (int64_t) ret * (P + 1 - n) % P;
    return ret;
}

int fac[20][2], cnt;
int m, n, ans;
void dfs(int pos, int num) {
    if (pos == cnt) {
        int tmp = (int64_t)((m - 1) / num + n / num + 1) *
                  (n / num - (m - 1) / num) % P * inv2 % P * f(num) % P;
        ans = (ans + tmp) % P;
        return;
    }
    for (int i = 0; i <= fac[pos][1]; i++) {
        dfs(pos + 1, num);
        num *= fac[pos][0];
    }
}

int main() {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mu[i] = 1 + P - i;
        }
        for (int j = 1; j <= prime[0] && i <= N / prime[j]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j])
                mu[i * prime[j]] = (int64_t) mu[i] * (P + 1 - prime[j]) % P;
            else {
                mu[i * prime[j]] = mu[i];
                break;
            }
        }
    }
    int T = read();
    while (T--) {
        m = read();
        n = read();
        int x = n;
        cnt = 0;
        for (int i = 1; i <= prime[0] && prime[i] <= x / prime[i]; i++) {
            if (x % prime[i] == 0) {
                fac[cnt][0] = prime[i];
                fac[cnt][1] = 0;
                while (x % prime[i] == 0) {
                    fac[cnt][1]++;
                    x /= prime[i];
                }
                cnt++;
            }
        }
        if (x > 1) {
            fac[cnt][0] = x;
            fac[cnt++][1] = 1;
        }
        ans = 0;
        dfs(0, 1);
        ans = (int64_t) n * ans % P;
        printf("%d\n", ans);
    }
    return 0;
}