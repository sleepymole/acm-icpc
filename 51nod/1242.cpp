#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000009;
struct Matrix {
    int mat[2][2];
    Matrix operator*(Matrix rhs) {
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] =
                        (ll)(res.mat[i][j] + (ll) mat[i][k] * rhs.mat[k][j]) %
                        mod;
                }
            }
        }
        return res;
    }
    Matrix operator^(ll n) {
        Matrix a = (*this);
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        res.mat[0][0] = res.mat[1][1] = 1;
        while (n) {
            if (n % 2) res = res * a;
            a = a * a;
            n /= 2;
        }
        return res;
    }
};

int main() {
    ll n;
    cin >> n;
    Matrix A;
    memset(A.mat, 0, sizeof(A.mat));
    A.mat[1][1] = 1;
    Matrix B;

    B.mat[0][0] = 0;
    B.mat[0][1] = B.mat[1][0] = B.mat[1][1] = 1;
    ;
    Matrix res = A * (B ^ n);
    cout << res.mat[1][0] << endl;
    return 0;
}