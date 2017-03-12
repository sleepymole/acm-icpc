#include <stdio.h>
#include <string.h>
const int maxn = 100010;
char str[maxn];

struct SegmentTree {
    char ch;
    int sumv[maxn * 3], setv[maxn * 3];
    void initial() { memset(setv, -1, sizeof(setv)); }
    void build(int o, int l, int r) {
        if (l == r) {
            if (str[l] == ch) sumv[o] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * o + 1, l, mid);
        build(2 * o + 2, mid + 1, r);
        sumv[o] = sumv[2 * o + 1] + sumv[2 * o + 2];
    }
    void pushdown(int o) {
        setv[2 * o + 1] = setv[o];
        setv[2 * o + 2] = setv[o];
        setv[o] = -1;
    }
    void update(int o, int l, int r, int sl, int sr, int v) {
        if (sl > sr) return;
        if (sr < l || sl > r) return;
        if (sl <= l && r <= sr) {
            setv[o] = v;
            return;
        }
        if (setv[o] >= 0) {
            pushdown(o);
        }
        int mid = (l + r) / 2;
        if (sl <= mid) update(2 * o + 1, l, mid, sl, sr, v);
        if (sr > mid) update(2 * o + 2, mid + 1, r, sl, sr, v);
        sumv[o] = 0;
        sumv[o] += setv[2 * o + 1] >= 0 ? (mid - l + 1) * setv[2 * o + 1]
                                        : sumv[2 * o + 1];
        sumv[o] += setv[2 * o + 2] >= 0 ? (r - mid) * setv[2 * o + 2]
                                        : sumv[2 * o + 2];
    }
    int query(int o, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (setv[o] >= 0) return (qr - ql + 1) * setv[o];
        if (l == ql && r == qr) return sumv[o];
        int mid = (l + r) / 2;
        return query(2 * o + 1, l, mid, ql, qr > mid ? mid : qr) +
               query(2 * o + 2, mid + 1, r, ql < mid + 1 ? mid + 1 : ql, qr);
    }
    void restore(int o, int l, int r) {
        if (l == r) {
            if (setv[o] == 1 || (setv[o] == -1 && sumv[o] == 1)) {
                str[l] = ch;
            }
            return;
        }
        if (setv[o] >= 0) pushdown(o);
        int mid = (l + r) / 2;
        restore(2 * o + 1, l, mid);
        restore(2 * o + 2, mid + 1, r);
    }
} seg[26];

inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main() {
    int n = read(), q = read();
    scanf("%s", str);
    for (int i = 0; i < 26; i++) {
        seg[i].initial();
        seg[i].ch = i + 'a';
        seg[i].build(0, 0, n - 1);
    }
    while (q--) {
        int l = read(), r = read(), k = read();
        l--, r--;
        int e = l - 1;
        if (k == 1) {
            for (int i = 0; i < 26; i++) {
                int cnt = seg[i].query(0, 0, n - 1, l, r);
                if (cnt == 0) continue;
                seg[i].update(0, 0, n - 1, l, e, 0);
                seg[i].update(0, 0, n - 1, e + 1, e + cnt, 1);
                seg[i].update(0, 0, n - 1, e + cnt + 1, r, 0);
                e += cnt;
            }
        } else {
            for (int i = 25; i >= 0; i--) {
                int cnt = seg[i].query(0, 0, n - 1, l, r);
                if (cnt == 0) continue;
                seg[i].update(0, 0, n - 1, l, e, 0);
                seg[i].update(0, 0, n - 1, e + 1, e + cnt, 1);
                seg[i].update(0, 0, n - 1, e + cnt + 1, r, 0);
                e += cnt;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        seg[i].restore(0, 0, n - 1);
    }
    printf("%s\n", str);
    return 0;
}