#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 50010;
int a[maxn], f[maxn][16];

void init(int n) {
    for (int i = 0; i < n; i++) f[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            f[i][j] = a[f[i][j - 1]] > a[f[i + (1 << (j - 1))][j - 1]]
                          ? f[i][j - 1]
                          : f[i + (1 << (j - 1))][j - 1];
        }
    }
}

int ask(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    return a[f[l][k]] > a[f[r - (1 << k) + 1][k]] ? f[l][k]
                                                  : f[r - (1 << k) + 1][k];
}

int count(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    int idx = ask(l, r);
    return max(count(l, idx - 1), count(idx + 1, r)) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    init(n);
    cout << count(0, n - 1) << endl;
    return 0;
}