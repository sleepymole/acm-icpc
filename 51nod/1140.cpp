#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
const int N = 500;

void input(int mat[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void mul(int mat[][N], int x[], int y[], int n) {
    memset(y, 0, n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += x[j] * mat[j][i];
        }
    }
}

int mat1[N][N], mat2[N][N], mat3[N][N];
int x[N], a[N], b[N], c[N];

int main() {
    int n;
    scanf("%d", &n);
    input(mat1, n);
    input(mat2, n);
    input(mat3, n);
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; i++) {
        x[i] = rand();
    }
    mul(mat1, x, a, n);
    cout << endl;
    mul(mat2, a, b, n);
    mul(mat3, x, a, n);
    bool equal = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            equal = false;
            break;
        }
    }
    if (equal)
        puts("Yes");
    else
        puts("No");
    return 0;
}