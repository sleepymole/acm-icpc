#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int64;
typedef __int128 int128;

int64 power_mod(int64 a, int64 n, int64 p) {
    int64 r = 1;
    while (n) {
        if (n & 1) r = (int128) r * a % p;
        a = (int128) a * a % p;
        n >>= 1;
    }
    return r;
}

bool witness(int64 a, int64 p) {
    int64 q = p - 1, k = 0;
    while (q % 2 == 0) {
        q >>= 1;
        k++;
    }
    int64 v = power_mod(a, q, p);
    if (v == 1 || v == p - 1) return false;
    while (k--) {
        v = (int128) v * v % p;
        if (v == 1 || v == p - 1) return false;
    }
    return true;
}

bool miller_rabin(int64 n) {
    if (n == 2) return true;
    if (n == 1 || n % 2 == 0) return false;
    for (int i = 0; i < 5; i++) {
        int a = rand() % (n - 1) + 1;
        if (witness(a, n)) return false;
    }
    return true;
}

int64 pollard_rho(int64 n) {
    int64 k = 2, x0 = 1, y = x0;
    int64 c = rand() % (n - 1) + 1;
    for (int i = 2;; i++) {
        x0 = ((int128) x0 * x0 + c) % n;
        int64 s = __gcd(abs(y - x0), n);
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

int64 ans, len;
bool check(int64 p) {
    v.clear();
    factor(p - 1);
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());
    int sz = v.size();
    for (int i = 0; i < sz; i++) {
        if (power_mod(10, (p - 1) / v[i], p) == 1) return false;
    }
    if (p - 1 > len) ans = p, len = p - 1;
    return true;
}

int main() {
    int64 n;
    cin >> n;
    int64 x = n;
    while (x && !(miller_rabin(x) && check(x))) x--;
    cout << ans << endl;
    return 0;
}