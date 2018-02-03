#include <cstring>
#include <iostream>
#include <queue>

const int MAXN = 300010;
int in[MAXN], f[MAXN][26];

struct Node {
    int to, next;
} e[MAXN];

int head[MAXN], tot;

inline void addEdge(int u, int v) {
    e[tot] = {v, head[u]};
    head[u] = tot++;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string str;
    std::cin >> str;
    memset(head, -1, sizeof(head));
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        addEdge(x, y);
        in[y]++;
    }
    std::queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            f[i][str[i - 1] - 'a'] = 1;
            Q.push(i);
        }
    }
    int cnt = 0, ans = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cnt++;
        for (int it = head[u]; ~it; it = e[it].next) {
            int v = e[it].to;
            in[v]--;
            for (int i = 0; i < 26; ++i) {
                f[v][i] = std::max(f[v][i], f[u][i] + (i + 'a' == str[v - 1]));
                ans = std::max(ans, f[v][i]);
            }
            if (!in[v]) Q.push(v);
        }
    }
    if (cnt == n) {
        std::cout << ans << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}