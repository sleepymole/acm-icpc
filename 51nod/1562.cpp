#include <iostream>
using namespace std;
const int maxn = 200010;
bool a[maxn], b[maxn];
int h1[maxn], h2[maxn], w1[maxn], w2[maxn];
long long ans[maxn];

struct input {
    int t, x;
} in[maxn];

int main() {
    ios::sync_with_stdio(false);
    int w, h, n;
    cin >> w >> h >> n;
    a[0] = a[w] = true;
    b[0] = b[h] = true;
    for (int i = 0; i < n; i++) {
        char ch = cin.get();
        while (ch != 'V' && ch != 'H') ch = cin.get();
        int x;
        cin >> x;
        if (ch == 'V') {
            in[i] = {0, x};
            a[x] = true;
        } else {
            in[i] = {1, x};
            b[x] = true;
        }
    }
    int maxA = 0, maxB = 0, p = 0;
    for (int i = 1; i < w; i++) {
        if (a[i]) {
            maxA = max(maxA, i - p);
            w1[i] = p;
            w2[p] = i;
            p = i;
        }
    }
    w1[w] = p;
    w2[p] = w;
    maxA = max(maxA, w - p);

    p = 0;
    for (int i = 1; i < h; i++) {
        if (b[i]) {
            maxB = max(maxB, i - p);
            h1[i] = p;
            h2[p] = i;
            p = i;
        }
    }
    h1[h] = p;
    h2[p] = h;
    maxB = max(maxB, h - p);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = 1LL * maxA * maxB;
        if (in[i].t == 0) {
            int l = w1[in[i].x], r = w2[in[i].x];
            maxA = max(maxA, r - l);
            w2[l] = r, w1[r] = l;
        } else {
            int l = h1[in[i].x], r = h2[in[i].x];
            maxB = max(maxB, r - l);
            h2[l] = r, h1[r] = l;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << "\n";
    return 0;
}