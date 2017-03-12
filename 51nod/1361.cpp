#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int P;

struct Matrix {
    int mat[2][2];
    Matrix() { memset(mat, 0, sizeof(mat)); }
    Matrix operator*(Matrix rhs) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] =
                        (ll)(res.mat[i][j] + (ll) mat[i][k] * rhs.mat[k][j]) %
                        P;
                }
            }
        }
        return res;
    }
    Matrix operator^(int n) {
        Matrix a = (*this);
        Matrix res;
        res.mat[0][0] = res.mat[1][1] = 1;
        while (n) {
            if (n % 2) res = res * a;
            a = a * a;
            n /= 2;
        }
        return res;
    }
};

int F(int n) {
    Matrix A, B;
    A.mat[1][0] = 11;
    A.mat[1][1] = 119;
    B.mat[0][1] = P - 1;
    B.mat[1][0] = 1;
    B.mat[1][1] = 11;
    Matrix res = A * (B ^ (n - 1));
    return res.mat[1][0];
}

int power_mod(int a, ll n, int p) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % p;
        a = (ll) a * a % p;
        n /= 2;
    }
    return r;
}

int getLoop(int p) {
    if (power_mod(117, (p - 1) / 2, p) == 1)
        return p - 1;
    else
        return p + 1;
}

int inverse(int a, int m) {
    return a == 1 ? 1 : (ll) inverse(m % a, m) * (m - m / a) % m;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld%d", &n, &P);
        if (P == 2 || P == 3) {
            puts("1");
            continue;
        }
        int loop = getLoop(P);
        int k = power_mod(2, n - 1, loop);
        if (k == 0) k = loop;
        int ans = (ll)(F(k) - 5 + P) * inverse(6 % P, P) % P;
        printf("%d\n", ans);
    }
    return 0;
}