#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 501;
int score[maxn];
bool vis[maxn];
int pre[maxn];
void Dijkstra(int dist[][maxn], int lowc[], int maxScore[], int n, int start) {
    for (int i = 0; i < n; i++) {
        lowc[i] = INF;
        vis[i] = false;
        pre[i] = -1;
        maxScore[i] = 0;
    }
    lowc[start] = 0;
    maxScore[start] = score[start];
    for (int j = 0; j < n; j++) {
        int k = -1;
        int minc = INF;
        int maxs = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i] &&
                (minc > lowc[i] || (minc == lowc[i] && (maxs < maxScore[i])))) {
                maxs = maxScore[i];
                minc = lowc[i];
                k = i;
            }
        }
        if (k == -1) break;
        vis[k] = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (lowc[i] > lowc[k] + dist[k][i] ||
                            (lowc[i] == lowc[k] + dist[k][i] &&
                             maxScore[i] < maxScore[k] + score[i]))) {
                lowc[i] = lowc[k] + dist[k][i];
                maxScore[i] = maxScore[k] + score[i];
                pre[i] = k;
            }
        }
    }
}
int dist[maxn][maxn];
int lowc[maxn], maxScore[maxn];
int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i != j) * INF;
        }
    }
    int x, y, z;
    while (m--) {
        cin >> x >> y >> z;
        dist[x][y] = dist[y][x] = z;
    }
    Dijkstra(dist, lowc, maxScore, n, start);
    cout << lowc[end] << " " << maxScore[end] << endl;
    return 0;
}