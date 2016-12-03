#include<iostream>
#include<stdint.h>
using namespace std;
int P;

int power_mod(int a, int64_t n) {
    int r = 1;
    while (n) {
        if (n & 1) r = (int64_t)r*a%P;
        a = (int64_t)a*a%P;
        n >>= 1;
    }
    return r;
}

struct Poly {
    int data[4];
    Poly() { data[0] = data[1] = data[2] = data[3] = 0; }
    Poly operator*(const Poly& rhs)const {
        Poly res;
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 2;j++) {
                res.data[i + j] = (res.data[i + j] + (int64_t)data[i] * rhs.data[j]) % P;
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
    Poly res, base;
    base.data[1] = res.data[0] = 1;
    while (n) {
        if (n & 1) res = res*base;
        base = base*base;
        n >>= 1;
    }
    return (res.data[0] + 2LL * res.data[1]) % P;
}

int main() {
    int64_t n, k, l;
    cin >> n >> k >> l >> P;
    if ((l < 62) && (k >= (1LL << l))) {
        cout << 0 << endl;
        return 0;
    }
    int A = power_mod(2, n), ans = 1;
    for (int i = 0;i < l;i++) {
        if (i == 63) ans = (int64_t)ans*fib(n) % P;
        else if (k&(1LL << i)) ans = (int64_t)ans*(A - fib(n)) % P;
        else ans = (int64_t)ans*fib(n) % P;
    }
    ans = (ans + P) % P;
    cout << ans << endl;
    return 0;
}