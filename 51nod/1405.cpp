#pragma comment(linker, "/STACK:10240000,10240000")
#include <stdint.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100000;

struct Edge {
    int next, to;
} e[2 * N + 1];
int head[N + 1], tot;
inline void addEdge(int x, int y) {
    e[tot].to = y;
    e[tot].next = head[x];
    head[x] = tot++;
}

int n, a[N + 1], vis[N + 1];
int64_t sum[N + 1];
void dfs1(int root) {
    vis[root] = 1;
    a[root] = 1;
    for (int i = head[root]; i != -1; i = e[i].next) {
        int u = e[i].to;
        if (!vis[u]) {
            dfs1(u);
            a[root] += a[u];
            sum[root] += sum[u] + a[u];
        }
    }
}

void dfs2(int root, int cur) {
    vis[cur] = 1;
    sum[cur] = sum[root] - 2 * a[cur] + n;
    for (int i = head[cur]; i != -1; i = e[i].next) {
        int u = e[i].to;
        if (!vis[u]) {
            dfs2(cur, u);
        }
    }
}

int main() {
    int x, y;
    scanf("%d", &n);
    memset(head, -1, (n + 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }
    dfs1(1);
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for (int i = head[1]; i != -1; i = e[i].next) {
        dfs2(1, e[i].to);
    }
    for (int i = 1; i <= n; i++) {
        printf("%I64d\n", sum[i]);
    }
    return 0;
}