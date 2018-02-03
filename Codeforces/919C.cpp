#include <iostream>

const int MAXN = 2010;
char str[MAXN][MAXN];

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> (str[i] + 1);
        int cnt = 0;
        for (int j = 1; j <= m; ++j) {
            if (str[i][j] == '.') {
                ++cnt;
            } else {
                if (cnt >= k) ans += cnt - k + 1;
                cnt = 0;
            }
        }
        if (cnt >= k) ans += cnt - k + 1;
    }
    for (int j = 1; j <= m; ++j) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (str[i][j] == '.') {
                ++cnt;
            } else {
                if (cnt >= k) ans += cnt - k + 1;
                cnt = 0;
            }
        }
        if (cnt >= k) ans += cnt - k + 1;
    }
    if (k == 1) ans /= 2;
    std::cout << ans << std::endl;
    return 0;
}