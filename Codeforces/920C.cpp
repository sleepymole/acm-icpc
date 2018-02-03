#include <iostream>

const int MAXN = 200010;
int a[MAXN];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::string str;
    std::cin >> str;
    int prev = 1;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (str[i - 1] == '0') {
            for (int j = prev; j <= i; ++j) {
                if (a[j] < prev || a[j] > i) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            prev = i + 1;
        }
    }
    std::cout << (flag ? "YES" : "NO") << std::endl;
    return 0;
}