#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1010;
char mp[MAXN][MAXN];
int u[MAXN][MAXN], d[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];
bool ans[26];

struct Point {
    int x, y;
    char c;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (mp[i - 1][j] != '#') u[i][j] = u[i - 1][j] + 1;
            if (mp[i][j - 1] != '#') l[i][j] = l[i][j - 1] + 1;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = m - 1; j >= 1; j--) {
            if (mp[i + 1][j] != '#') d[i][j] = d[i + 1][j] + 1;
            if (mp[i][j + 1] != '#') r[i][j] = r[i][j + 1] + 1;
        }
    }
    queue<Point> Q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (isalpha(mp[i][j])) Q.push({i, j, mp[i][j]});
    int k, s;
    scanf("%d", &k);
    while (k--) {
        char dir = getchar();
        while (!isalpha(dir)) dir = getchar();
        scanf("%d", &s);
        queue<Point> T;
        while (!Q.empty()) {
            Point p = Q.front();
            Q.pop();
            if (dir == 'N') {
                if (u[p.x][p.y] >= s) {
                    p.x -= s;
                    T.push(p);
                }
            } else if (dir == 'S') {
                if (d[p.x][p.y] >= s) {
                    p.x += s;
                    T.push(p);
                }
            } else if (dir == 'E') {
                if (r[p.x][p.y] >= s) {
                    p.y += s;
                    T.push(p);
                }
            } else {
                if (l[p.x][p.y] >= s) {
                    p.y -= s;
                    T.push(p);
                }
            }
        }
        Q = move(T);
    }
    if (!Q.size())
        puts("no solution");
    else {
        while (!Q.empty()) {
            ans[Q.front().c - 'A'] = true;
            Q.pop();
        }
        for (int i = 0; i < 26; i++)
            if (ans[i]) putchar(i + 'A');
        putchar('\n');
    }
    return 0;
}