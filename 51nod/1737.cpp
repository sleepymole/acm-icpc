#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100010;

struct Edge {
    int to, dist, next;
} e[maxn * 2];
int head[maxn], tot;
inline void addEdge(int u, int v, int d) {
    e[tot] = {v, d, head[u]};
    head[u] = tot++;
}

int c[maxn], g, d, n;
void dfs(int u) {
    c[u] = 1;
    int tmp = 0;
    for (int it = head[u]; it != -1; it = e[it].next) {
        int v = e[it].to;
        if (c[v]) continue;
        dfs(v);
        c[u] += c[v];
        tmp = max(tmp, c[v]);
    }
    tmp = max(tmp, n - c[u]);
    if (tmp < d) {
        d = tmp;
        g = u;
    }
}

long long dfs2(int u) {
    c[u] = 1;
    long long s = 0;
    for (int it = head[u]; it != -1; it = e[it].next) {
        int v = e[it].to;
        if (c[v]) continue;
        s += dfs2(v);
        s += (long long) c[v] * e[it].dist;
        c[u] += c[v];
    }
    return s;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    int x, y, z;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &x, &y, &z);
        addEdge(x, y, z);
        addEdge(y, x, z);
    }
    d = n;
    dfs(1);
    memset(c, 0, sizeof(c));
    printf("%lld\n", dfs2(g));
    return 0;
}