#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 25010;
const int maxm = 100010;

struct Edge {
    int next, to;
}e[maxm];
int head[maxn], tot;
inline void addEdge(int u, int v) {
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot++;
}

bool bridge[maxm];
int dfs_clock, pre[maxn], low[maxn];
void dfs(int u, int fa) {
    low[u] = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = head[u];i != -1;i = e[i].next) {
        int v = e[i].to;
        if (!pre[v]) {
            child++;
            dfs(v, u);
            if (low[v] < low[u]) low[u] = low[v];
            if (low[v] > pre[u]) bridge[i] = true;
        }
        else if (pre[v] < pre[u] && v != fa) {
            if (pre[v] < low[u]) low[u] = pre[v];
        }
    }
}

int belong[maxn], vis[maxn], cnt;
void dfs2(int u) {
    vis[u] = true;
    belong[u] = cnt;
    for (int i = head[u];i != -1;i = e[i].next) {
        if (!vis[e[i].to] && !bridge[i]) {
            dfs2(e[i].to);
        }
    }
}

int main() {
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for (int i = 0;i < m;i++) {
        scanf("%d%d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }
    for (int i = 1;i <= n;i++) {
        if (!pre[i]) dfs(i, -1);
    }
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            cnt++;
            dfs2(i);
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &x, &y);
        if (belong[x] == belong[y]) puts("Yes");
        else puts("No");
    }
    return 0;
}