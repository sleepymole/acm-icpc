#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 510;
int a[maxn][maxn], n, m;
int sum[maxn][maxn];

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i-1][j] + a[i][j];
        }
    }
    int s, ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            s = 0;
            for (int k = 1;k <= m;k++) {
                if (sum[j][k] - sum[i - 1][k] != j - i + 1) s = 0;
                else s += j - i + 1;
                if (s > ans) ans = s;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}