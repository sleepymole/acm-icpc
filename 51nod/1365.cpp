#include <stdint.h>
#include <cstdio>
const int P = 1000000007;

int64_t read() {
    int64_t x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x;
}

struct Poly {
    int data[4];
    Poly() { data[0] = data[1] = data[2] = data[3] = 0; }
    Poly operator*(const Poly& rhs) const {
        Poly res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.data[i + j] =
                    (res.data[i + j] + (int64_t) data[i] * rhs.data[j]) % P;
            }
        }
        res.data[2] = (res.data[2] + res.data[3]) % P;
        res.data[1] = (res.data[1] + res.data[3]) % P;
        res.data[1] = (res.data[1] + res.data[2]) % P;
        res.data[0] = (res.data[0] + res.data[2]) % P;
        return res;
    }
};

int fib(int64_t n) {
    Poly A, res;
    A.data[1] = res.data[0] = 1;
    int64_t x = n > 0 ? n : -n;
    while (x) {
        if (x & 1) res = res * A;
        A = A * A;
        x >>= 1;
    }
    int ans = res.data[1];
    if (n < 0 && n % 2 == 0) ans = -ans;
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int64_t m = read(), k = read();
        int64_t i = m / k, j = m % k, ans;
        if (i % 2 == 0) {
            ans = fib(j);
            if (i * k / 2 % 2 == 1) ans = (fib(k) - ans + P) % P;
        } else {
            ans = fib(j - k);
            if ((i + 1) * k / 2 % 2 == 1) ans = -ans;
            if (ans < 0) ans = (fib(k) + ans + P) % P;
        }
        printf("%d\n", ans);
    }
    return 0;
}