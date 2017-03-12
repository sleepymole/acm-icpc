#include <iostream>
using namespace std;
const int maxn = 501;
int matrix[maxn][maxn];
int f[maxn][maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + matrix[i][j];
        }
    }
    cout << f[n][n] << endl;
    return 0;
}