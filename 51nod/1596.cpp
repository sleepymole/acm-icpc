#include <cstdio>
const int maxn = 1000010;
int a[maxn];

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    int ans = 0;
    for (int i = 0; i < 1000000; i++) {
        if (a[i] & 1) ans++;
        a[i + 1] += a[i] / 2;
    }
    x = a[1000000];
    for (int i = 0; i < 20; i++) {
        if (x & (1 << i)) ans++;
    }
    printf("%d", ans);
    return 0;
}
