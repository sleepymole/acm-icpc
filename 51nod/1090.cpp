#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a[1001];
int read() {
    int x = 0;
    char ch = getchar();
    while (!(ch == '-' || (ch >= '0' && ch <= '9'))) {
        ch = getchar();
    }
    if (ch == '-') {
        ch = getchar();
        while (ch >= '0' && ch <= '9') {
            x = x * 10 - ch + '0';
            ch = getchar();
        }
    } else {
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
    }
    return x;
}

void write(int n) {
    if (n < 0) putchar('-'), n *= -1;
    if (n >= 10) write(n / 10);
    putchar(n % 10 + '0');
}
int main() {
    int n;
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    sort(a, a + n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == 0) {
                    write(a[i]);
                    putchar(' ');
                    write(a[j]);
                    putchar(' ');
                    write(a[k]);
                    putchar('\n');
                    flag = true;
                }
            }
        }
    }
    if (!flag) printf("No Solution\n");
    return 0;
}