#include <cstdlib>
#include <iostream>
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

int main() {
    int64 p;
    while (cin >> p) {
        if (miller_rabin(p))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}