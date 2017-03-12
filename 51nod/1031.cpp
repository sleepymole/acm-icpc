#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
struct Matrix {
    int mat[2][2];
    Matrix operator*(const Matrix &rhs) {
        Matrix ans;
        memset(ans.mat, 0, sizeof(ans.mat));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ans.mat[i][j] =
                        (ans.mat[i][j] + (ll) mat[i][k] * rhs.mat[k][j] % mod) %
                        mod;
                }
            }
        }
        return ans;
    }
    Matrix operator^(int n) {
        Matrix r, a = (*this);
        memset(r.mat, 0, sizeof(r.mat));
        for (int i = 0; i < 2; i++) r.mat[i][i] = 1;
        while (n) {
            if (n % 2) r = r * a;
            a = a * a;
            n /= 2;
        }
        return r;
    }
};

int main() {
    int n;
    cin >> n;
    Matrix A, B;
    A.mat[0][0] = 0;
    A.mat[0][1] = 1;
    A.mat[1][0] = 1;
    A.mat[1][1] = 1;
    B.mat[0][0] = 0;
    B.mat[0][0] = 0;
    B.mat[1][0] = 1;
    B.mat[1][1] = 2;
    Matrix C = B * (A ^ (n - 1));
    cout << C.mat[1][0] << endl;
    return 0;
}