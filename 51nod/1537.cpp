#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int inverse(int a, int m) {
    return a == 1 ? 1 : (ll) inverse(m % a, m) * (m - m / a) % mod;
}

ll read() {
    ll x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void write(int n) {
    if (n >= 10) write(n / 10);
    putchar(n % 10 + '0');
}

int power_mod(int a, int n) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % mod;
        a = (ll) a * a % mod;
        n /= 2;
    }
    return r;
}

int main() {
    int n = read() % (mod - 1);
    int ans = (power_mod(59713601, n) + power_mod(59713599, n)) % mod;
    ans = (ll) ans * 500000004 % mod;
    ans = (ll) ans * ans % mod;
    write(ans);
    putchar('\n');
    return 0;
}