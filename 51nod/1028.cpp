#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const double PI = acos(-1.0);

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

void fft(Complex a[], int len, int on) {
    for (int i = 0, j = 0; i < len; i++) {
        if (i < j) swap(a[i], a[j]);
        for (int k = len >> 1; (j ^= k) < k; k >>= 1)
            ;
    }
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = a[k];
                Complex t = w * a[k + h / 2];
                a[k] = u + t;
                a[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < len; i++) {
            a[i].x /= len;
        }
    }
}

const int maxn = 100010;
char str1[maxn], str2[maxn];
Complex a[maxn * 3], b[maxn * 3];
int sum[maxn * 3];

int main() {
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = 1;
    while (len < len1 * 2 || len < len2 * 2) len <<= 1;
    for (int i = 0; i < len1; i++) {
        a[i].x = str1[len1 - 1 - i] - '0';
    }
    for (int i = 0; i < len2; i++) {
        b[i].x = str2[len2 - 1 - i] - '0';
    }
    fft(a, len, 1);
    fft(b, len, 1);
    for (int i = 0; i < len; i++) {
        a[i] = a[i] * b[i];
    }
    fft(a, len, -1);
    for (int i = 0; i < len; i++) {
        sum[i] = (int) (a[i].x + 0.5);
    }
    for (int i = 0; i < len; i++) {
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    len = len1 + len2 - 1;
    while (len > 0 && sum[len] == 0) len--;
    for (int i = len; i >= 0; i--) {
        putchar(sum[i] + '0');
    }
    cout << endl;
    return 0;
}