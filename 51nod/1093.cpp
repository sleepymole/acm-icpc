#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-12;

double cost(double n, int r, int k) {
    if ((n - k / (2 * r + 1)) < eps) {
        if (r == 0) return n;
        int i = ceil((r * k - n) / (k - 2 * n));
        return (2 * i - 1) * n;
    }
    double s = 1.0 * k / (2 * r + 1);
    return k + cost(n - s, r + 1, k);
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << int(ceil(cost(N, 0, K))) << endl;
    return 0;
}