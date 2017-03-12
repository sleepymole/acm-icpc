#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdint.h>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int P = 1000000007;
const int N = 100000;
vector<int> e[N + 1];
bool vis[N + 1];

int fac[N + 1], fac_inv[N + 1], inv[N + 1];
inline int combination(int n, int m) {
    return n >= m ? (int64_t) fac[n] * fac_inv[m] % P * fac_inv[n - m] % P : 0;
}

int n, k, ans;
int dfs(int root) {
    vis[root] = true;
    int sub = 1;
    for (int i = 0; i < e[root].size(); i++) {
        int u = e[root][i];
        if (!vis[u]) sub += dfs(u);
    }
    ans = (1LL * ans - combination(sub, k) - combination(n - sub, k)) % P;
    return sub;
}

int main() {
    inv[1] = fac[0] = fac[1] = fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (int64_t) inv[P % i] * (P - P / i) % P;
        fac[i] = (int64_t) fac[i - 1] * i % P;
        fac_inv[i] = (int64_t) fac_inv[i - 1] * inv[i] % P;
    }
    int x, y;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    ans = (int64_t) n * combination(n, k) % P;
    dfs(1);
    ans = (ans + P) % P;
    printf("%d\n", ans);
    return 0;
}