#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int P = 1000000007;
const int N = 100;
int f[N + 1][N + 1][N + 1];
vector<int> d[N + 1];
int prime[N + 1], mu[N + 1];
struct Edge {
    int from, to, value;
} e[50010];
const int MAXS = 1 << 21;
char buf[MAXS];
int ptr;
inline void ReadData() { fread(buf, 1, MAXS, stdin); }
inline char GetChar() { return buf[ptr++]; }
inline int Read() {
    int x = 0;
    char ch = GetChar();
    while (ch < '0' || ch > '9') ch = GetChar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = GetChar();
    }
    return x;
}

int main() {
    ReadData();
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i) d[j].push_back(i);
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
    int n = Read(), m = Read(), ans = 0;
    for (int i = 1; i <= m; i++) {
        int x = Read(), y = Read(), z = Read();
        e[i] = {x, y, z};
        for (auto k : d[z]) {
            f[x][y][k]++;
            ans += mu[k];
        }
    }
    for (int x = 1; x <= N; x++) {
        if (mu[x] == 0) continue;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (f[i][k][x] == 0) continue;
                for (int j = 1; j <= n; j++) {
                    int tmp = (ll) f[i][k][x] * f[k][j][x] % P;
                    f[i][j][x] = (f[i][j][x] + tmp) % P;
                    ans = (ans + mu[x] * tmp) % P;
                }
            }
        }
    }
    ans = (ans + P) % P;
    printf("%d\n", ans);
    int T = Read();
    while (T--) {
        int a = Read(), b = Read();
        int x = e[a].from, y = e[a].to;
        for (auto k : d[e[a].value]) {
            if (mu[k] == 0) continue;
            for (int i = 1; i <= n; i++) {
                if (f[i][x][k]) {
                    for (int j = 1; j <= n; j++) {
                        f[i][j][k] =
                            (f[i][j][k] - (ll) f[i][x][k] * f[y][j][k]) % P;
                        ans = (ans - (ll) mu[k] * f[i][x][k] * f[y][j][k]) % P;
                    }
                }
                f[i][y][k] = (f[i][y][k] - f[i][x][k]) % P;
                f[x][i][k] = (f[x][i][k] - f[y][i][k]) % P;
                ans = (ans - mu[k] * f[i][x][k]) % P;
                ans = (ans - mu[k] * f[y][i][k]) % P;
            }
            f[x][y][k]--;
            ans -= mu[k];
        }
        e[a].value = b;
        for (auto k : d[b]) {
            if (mu[k] == 0) continue;
            for (int i = 1; i <= n; i++) {
                if (f[i][x][k]) {
                    for (int j = 1; j <= n; j++) {
                        f[i][j][k] =
                            (f[i][j][k] + (ll) f[i][x][k] * f[y][j][k]) % P;
                        ans = (ans + (ll) mu[k] * f[i][x][k] * f[y][j][k]) % P;
                    }
                }
                f[i][y][k] = (f[i][y][k] + f[i][x][k]) % P;
                f[x][i][k] = (f[x][i][k] + f[y][i][k]) % P;
                ans = (ans + mu[k] * f[i][x][k]) % P;
                ans = (ans + mu[k] * f[y][i][k]) % P;
            }
            f[x][y][k]++;
            ans += mu[k];
        }
        ans = (ans + P) % P;
        printf("%d\n", ans);
    }
    return 0;
}