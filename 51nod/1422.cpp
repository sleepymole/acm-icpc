#include <assert.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100010;

struct Segment {
    ll l, r, p, c, v;
} s[maxn];

int main() {
    int m;
    scanf("%d", &m);
    ll p = 1;
    for (int i = 0; i < m; i++) {
        int t, x, y;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x);
            s[i] = {p, p, 0, 0, x};
            p++;
        } else {
            scanf("%d%d", &x, &y);
            s[i] = {p, p + x * y - 1, x, y, -1};
            p += x * y;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        int l = 0, r = m - 1, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (s[mid].l <= x && s[mid].r >= x) {
                pos = mid;
                break;
            } else if (x > s[mid].r) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        while (s[pos].v == -1) {
            x = (x - s[pos].l + 1) % s[pos].p;
            if (x == 0) x = s[pos].p;
            int l = 0, r = pos - 1;
            pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (s[mid].l <= x && s[mid].r >= x) {
                    pos = mid;
                    break;
                } else if (x > s[mid].r) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        printf("%lld ", s[pos].v);
    }
    printf("\n");
    return 0;
}