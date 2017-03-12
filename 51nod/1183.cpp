#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
char a[1001], b[1001];
int dp[1001][1001];

int Min(int a, int b, int c) { return min(min(a, b), c); }
int main() {
    scanf("%s%s", a + 1, b + 1);
    int m = strlen(a + 1);
    int n = strlen(b + 1);
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] =
                    Min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}