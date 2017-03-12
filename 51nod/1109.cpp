#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

void initial(int a[], int n) {
    a[0] = 1;
    for (int i = 1; i < 30; i++) {
        a[i] = (ll) a[i - 1] * 10 % n;
    }
}
int main() {
    int a[30], n, sum;
    cin >> n;
    initial(a, n);
    for (int i = 1; i < (1 << 30); i++) {
        sum = 0;
        for (int j = 0; j < 30; j++) {
            if (i & (1 << j)) {
                sum = (sum + a[j]) % n;
            }
        }
        if (sum == 0) {
            int p = 29;
            while ((i & (1 << p)) == 0) p--;
            for (int j = p; j >= 0; j--) {
                if (i & (1 << j))
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
            break;
        }
    }
    return 0;
}