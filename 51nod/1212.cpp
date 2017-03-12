#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1001;
typedef long long ll;
int lowc[maxn], dist[maxn][maxn];
bool vis[maxn];

ll Prim(int n) {
    vis[1] = true;
    for (int i = 2; i <= n; i++) {
        lowc[i] = dist[1][i];
    }
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        int minc = inf, p = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && minc > lowc[j]) {
                minc = lowc[j];
                p = j;
            }
        }
        ans += minc;
        vis[p] = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && lowc[j] > dist[p][j]) {
                lowc[j] = dist[p][j];
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i != j) * inf;
        }
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
    }
    cout << Prim(n) << endl;
    return 0;
}