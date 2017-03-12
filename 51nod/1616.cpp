#include <cstdio>
const int maxN = 1000000;
int num[maxN + 1];

int main() {
    int n, x;
    scanf("%d", &n);
    int N = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        num[x] = 1;
        if (x > N) N = x;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            num[i] += num[j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) continue;
        int flag = true;
        for (int j = i + i; j <= N; j += i) {
            if (num[j] >= num[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}