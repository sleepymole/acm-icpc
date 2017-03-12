#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
const double PI = acos(-1.0);
const int N = 1 << 20;
int ans[N];

struct Complex {
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
    Complex operator+(const Complex& rhs) const {
        return Complex(x + rhs.x, y + rhs.y);
    }
    Complex operator-(const Complex& rhs) const {
        return Complex(x - rhs.x, y - rhs.y);
    }
    Complex operator*(const Complex& rhs) const {
        return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
    }
};

void transform(Complex x[], int n, int on) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(x[i], x[j]);
        for (int k = n >> 1; (j ^= k) < k; k >>= 1)
            ;
    }
    for (int h = 2; h <= n; h <<= 1) {
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
        for (int j = 0; j < n; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = x[k], t = w * x[k + h / 2];
                x[k] = u + t;
                x[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < n; i++) {
            x[i].x = x[i].x / n;
        }
    }
}

void solve(int a[], int l, int r) {
    if (l == r) {
        int k = 0;
        a[k] = l;
        while (a[k]) {
            a[k + 1] += a[k] / 10;
            a[k] %= 10;
            k++;
        }
        return;
    }
    int p = 1;
    while (p < (9 * (r - l))) p <<= 1;
    Complex* x = new Complex[p];
    Complex* y = new Complex[p];
    int mid = (l + r) / 2;
    fill(a, a + p, 0);
    solve(a, l, mid);
    for (int i = 0; i < p; i++) {
        x[i] = Complex(a[i], 0);
    }
    fill(a, a + p, 0);
    solve(a, mid + 1, r);
    for (int i = 0; i < p; i++) {
        y[i] = Complex(a[i], 0);
    }
    transform(x, p, 1);
    transform(y, p, 1);
    for (int i = 0; i < p; i++) {
        x[i] = x[i] * y[i];
    }
    transform(x, p, -1);
    for (int i = 0; i < p; i++) {
        a[i] = (int) (x[i].x + 0.5);
    }
    for (int i = 0; i < p - 1; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    delete[] x;
    x = NULL;
    delete[] y;
    y = NULL;
}

int main() {
    int n;
    cin >> n;
    solve(ans, 1, n);
    int p = 5 * n;
    while (p > 0 && ans[p] == 0) p--;
    for (int i = p, k = 1; i >= 0; i--, k++) {
        putchar(ans[i] + '0');
        if (k % 1000 == 0) putchar('\n');
    }
    return 0;
}