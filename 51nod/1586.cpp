#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int prime[maxn / 10], cnt;
int e[maxn], div_num[maxn];
bool notprime[maxn];

void get_prime() {
    div_num[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!notprime[i]) {
            prime[cnt++] = i;
            e[i] = 1;
            div_num[i] = 2;
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                div_num[i * prime[j]] = div_num[i] / (e[i] + 1) * (e[i] + 2);
                e[i * prime[j]] = e[i] + 1;
                break;
            } else {
                div_num[i * prime[j]] = div_num[i] * div_num[prime[j]];
                e[i * prime[j]] = 1;
            }
        }
    }
}

int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void write(ll n) {
    if (n >= 10) write(n / 10);
    putchar(n % 10 + '0');
}

ll f[maxn];
int main() {
    get_prime();
    int cmd, x, y;
    int n = read(), q = read();
    while (q--) {
        cmd = read();
        if (cmd == 1) {
            x = read();
            y = read();
            for (int i = 1; i * x <= n; i++) {
                f[i * x] += (ll) div_num[i] * y;
            }
        } else {
            x = read();
            write(f[x]);
            putchar('\n');
        }
    }
    return 0;
}