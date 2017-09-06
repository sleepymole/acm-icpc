#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 110, M = 20010;

struct Edge {
    int to, next;
} e[M];
int head[N], tot;
void addEdge(int u, int v) {
    e[tot] = {v, head[u]};
    head[u] = tot++;
}

int matching[N], pre[N], vis[N];

int main() {
    int m, n, u, v;
    scanf("%d%d", &m, &n);
    memset(head, -1, sizeof(head));
    while (~scanf("%d%d", &u, &v)) {
        if (u == -1 && v == -1) break;
        addEdge(u, v);
        addEdge(v, u);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (!matching[i]) {
            queue<int> Q;
            Q.push(i);
            pre[i] = -1;
            bool found = false;
            while (!Q.empty() && !found) {
                int u = Q.front();
                Q.pop();
                for (int it = head[u]; ~it; it = e[it].next) {
                    int v = e[it].to;
                    if (vis[v] != i) {
                        vis[v] = i;
                        if (matching[v]) {
                            pre[matching[v]] = u;
                            Q.push(matching[v]);
                        } else {
                            found = true;
                            int d = u, e = v;
                            while (d != -1) {
                                int t = matching[d];
                                matching[d] = e;
                                matching[e] = d;
                                d = pre[d];
                                e = t;
                            }
                            break;
                        }
                    }
                }
            }
        }
        if (matching[i]) ans++;
    }
    if (ans == 0)
        puts("No Solution!");
    else
        printf("%d\n", ans);
    return 0;
}