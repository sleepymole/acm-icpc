#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

struct Matrix {
    int mat[3][3];
    Matrix operator*(Matrix rhs) {
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
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
        res.mat[2][2] = 1;
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
    Matrix A, B;
    memset(A.mat, 0, sizeof(A.mat));
    memset(B.mat, 0, sizeof(B.mat));
    A.mat[2][0] = 1;
    A.mat[2][1] = 2;
    A.mat[2][2] = 4;
    B.mat[1][0] = 1;
    B.mat[2][1] = 1;
    B.mat[0][2] = 1;
    B.mat[1][2] = -1;
    B.mat[2][2] = 2;
    Matrix res = A * (B ^ n);
    int ans = res.mat[2][0];
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}