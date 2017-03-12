#include <stdio.h>
const int N = 1000000;
int f[N + 1];

inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x;
}

int main() {
    int n = read();
    for (int i = 0; i < n; i++) {
        f[read()] = 1;
    }
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            if (f[j] && (f[i] + 1 > f[j])) {
                f[j] = f[i] + 1;
                if (f[j] > ans) ans = f[j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}