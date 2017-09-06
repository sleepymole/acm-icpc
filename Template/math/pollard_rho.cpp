#include <iostream>
#include <vector>
using namespace std;
typedef long long int64;
typedef __int128 int128;

int64 power_mod(int64 a, int64 n, int64 m) {
    int64 r = 1;
    while (n) {
        if (n % 2) r = (int128) r * a % m;
        a = (int128) a * a % m;
        n /= 2;
    }
    return r;
}

bool witness(int64 a, int64 p) {
    int64 q = p - 1, k = 0;
    while (q % 2 == 0) {
        k++;
        q /= 2;
    }
    int64 v = power_mod(a, q, p);
    if (v == 1 || v == p - 1) return false;
    while (k--) {
        v = (int128) v * v % p;
        if (v == p - 1) return false;
    }
    return true;
}

bool miller_rabin(int64 p) {
    if (p == 2) return true;
    if (p == 1 || p % 2 == 0) return false;
    for (int i = 0; i < 50; i++) {
        int64 a = rand() % (p - 1) + 1;
        if (witness(a, p)) return false;
    }
    return true;
}

int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }

int64 pollard_rho(int64 n) {
    int64 k = 2, x0 = 1, y = x0;
    int64 c = rand() % (n - 1) + 1;
    for (int i = 2;; i++) {
        x0 = ((int128) x0 * x0 + c) % n;
        int64 s = gcd(abs(y - x0), n);
        if (s != 1 && s != n) return s;
        if (y == x0) return n;
        if (i == k) y = x0, k <<= 1;
    }
}

vector<int64> v;
void factor(int64 n) {
    if (miller_rabin(n)) {
        v.push_back(n);
        return;
    }
    int64 d = n;
    while (d == n) d = pollard_rho(n);
    factor(d);
    factor(n / d);
}

int main() {
    int64 n;
    while (cin >> n) {
        v.clear();
        factor(n);
    }
    return 0;
}