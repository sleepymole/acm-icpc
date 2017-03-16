#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10010;

struct P {
    int m, s, idx;
    bool operator<(const P& rhs) const { return m < rhs.m; }
} p[maxn];

struct T {
    int x, y;
    double t;
    bool operator<(const T& rhs) const {
        if (t < rhs.t) return true;
        if (t == rhs.t) return x < rhs.x || ((x == rhs.x) && y < rhs.y);
        return false;
    }
} t[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].m, &p[i].s);
        p[i].idx = i;
    }
    sort(p + 1, p + n + 1);
    priority_queue<T> q;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].s > p[j].s) {
                double t = 1.0 * (p[i].m - p[j].m) / (p[j].s - p[i].s);
                T tmp = {p[i].idx, p[j].idx, t};
                if (int(q.size()) == 10000) {
                    if (tmp < q.top()) {
                        q.pop();
                        q.push(tmp);
                    }
                } else {
                    q.push(tmp);
                }
            }
        }
    }
    n = 0;
    while (!q.empty()) {
        t[n++] = q.top();
        q.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d %d\n", t[i].x, t[i].y);
    }
    return 0;
}