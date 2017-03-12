#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100010;
char str[maxn];
int a[maxn];

int main() {
    scanf("%s", str);
    int len1 = strlen(str);
    for (int i = len1 - 1; i >= 0; i--) {
        a[len1 - 1 - i] = str[i] - '0';
    }
    scanf("%s", str);
    int len2 = strlen(str);
    for (int i = len2 - 1; i >= 0; i--) {
        a[len2 - 1 - i] -= str[i] - '0';
    }
    int len = max(len1, len2);
    bool flag = true;
    for (int i = len; i > 1; i--) {
        if (a[i] > 10) {
            putchar('>');
            flag = false;
            break;
        } else if (a[i] < -10) {
            putchar('<');
            flag = false;
            break;
        }
        a[i - 1] += a[i];
        a[i - 2] += a[i];
    }
    if (flag) {
        if (a[0] == 0 && a[1] == 0)
            putchar('=');
        else {
            double x = a[0] + (sqrt(5) + 1) * a[1] / 2;
            if (x > 0)
                putchar('>');
            else
                putchar('<');
        }
    }
    return 0;
}