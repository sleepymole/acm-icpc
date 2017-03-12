#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int n, m;

struct Matrix {
    int mat[100][100];
    Matrix operator*(const Matrix &rhs) {
        Matrix ans;
        memset(ans.mat, 0, sizeof(ans.mat));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ans.mat[i][j] =
                        (ans.mat[i][j] + (ll) mat[i][k] * rhs.mat[k][j] % mod) %
                        mod;
                }
            }
        }
        return ans;
    }
    Matrix operator^(int m) {
        Matrix r, a = (*this);
        memset(r.mat, 0, sizeof(r.mat));
        for (int i = 0; i < n; i++) r.mat[i][i] = 1;
        while (m) {
            if (m % 2) r = r * a;
            a = a * a;
            m /= 2;
        }
        return r;
    }
};

int main() {
    cin >> n >> m;
    Matrix A;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A.mat[i][j];
        }
    }
    Matrix res = A ^ m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res.mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}