#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[maxn], b[maxn], m;

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
    int n = read();
    int k = read();
    int S = 0, QS = 0;
    bool flag = false;
    memset(a, -1, sizeof(a));
    while (n--) {
        int t = read();
        switch (t) {
            case 1: {
                int v = read();
                if (a[m] == -1) {
                    a[m] = v;
                    S += v;
                    QS += v * v;
                    m = (m + 1) % k;
                    if (m == 0) flag = true;
                } else {
                    S = S - a[m] + v;
                    QS = QS - a[m] * a[m] + v * v;
                    a[m] = v;
                    m = (m + 1) % k;
                }
                break;
            }
            case 2:
                if (flag)
                    printf("%.2f\n", double(S / k));
                else
                    printf("%.2f\n", double(S / m));
                break;
            case 3:
                if (flag)
                    printf("%.2f\n", 1.0 * QS / k - 1.0 * S * S / k / k);
                else
                    printf("%.2f\n", 1.0 * QS / m - 1.0 * S * S / m / m);
                break;
            case 4: {
                if (flag) {
                    memcpy(b, a, k * sizeof(int));
                    sort(b, b + k);
                    if (k % 2 == 1)
                        printf("%d.00\n", b[k / 2]);
                    else
                        printf("%.2f\n", 1.0 * (b[k / 2] + b[k / 2 - 1]) / 2);
                } else {
                    memcpy(b, a, m * sizeof(int));
                    sort(b, b + m);
                    if (m % 2 == 1)
                        printf("%d.00\n", b[m / 2]);
                    else
                        printf("%.2f\n", 1.0 * (b[m / 2] + b[m / 2 - 1]) / 2);
                }
                break;
            }
        }
    }
    return 0;
}