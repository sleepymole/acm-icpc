#include <stdio.h>
const int mid = 1000010;
int a[mid * 2], b[mid * 2];

int main() {
    int k = 1, sum = 0, ans = 0;
    char ch;
    while (true) {
        ch = getchar();
        if (ch == '1')
            sum++;
        else if (ch == '0')
            sum--;
        else
            break;
        if (sum == 0) {
            if (k > ans) ans = k;
        } else if (a[mid + sum] == 0) {
            a[mid + sum] = k;
        } else {
            b[mid + sum] = k;
            if (k - a[mid + sum] + 1 > ans) ans = k - a[mid + sum];
        }
        k++;
    }
    printf("%d\n", ans);
    return 0;
}